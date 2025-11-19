#pragma once

#include <errno.h>
#include <fcntl.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

class LinuxFifo {
  public:
  LinuxFifo(const std::string& name = "/temp/tong/pipe", int socket_flags = O_RDWR)
      : name_(name), socket_flags_(socket_flags) {}
  ~LinuxFifo() { this->Close(); }

  public:
  bool Open() {
    // 0.close previous
    this->Close();

    // create folder if not exist
    size_t found = name_.rfind('/');
    if (found != std::string::npos) {
      std::string folder = name_.substr(0, found);
      std::string cmd = "mkdir -p " + folder;
      int ret = system(cmd.c_str());
      if (ret != 0) {
        printf("mkdir failed . \n");
        return false;
      }
    }

    int ret = mkfifo(name_.c_str(), 0666);
    if (ret < 0 && errno != EEXIST) {
      printf("mkfifo failed . errno : %d \n", errno);
      return false;
    }

    // 1.Create socket
    fd_ = open(name_.c_str(), socket_flags_);
    if (fd_ < 0) {
      printf("open pipe failed .\n");
      return false;
    }

    return true;
  }

  bool Close() {
    if (fd_ >= 0) {
      close(fd_);
      fd_ = -1;
    }
    return true;
  }

  int GetFileDescriptor() const { return fd_; }

  /// blocking , return 0 if success , use epoll or select to check if readable
  int RecvOnce(std::vector<uint8_t>& data) {
    if (fd_ < 0) {
      printf("error : not open \n");
      return -1;
    }

    int nbytes;
    nbytes = read(fd_, data.data(), data.size());

    if (nbytes < 0) {
      printf("error :  read error : %d  \n", errno);
      return -1;
    }
    return nbytes;
  }

  int SendOnce(const std::vector<uint8_t>& data) {
    if (fd_ < 0) {
      printf("error : CAN not open \n");
      return -1;
    }

    int nbytes = write(fd_, data.data(), data.size());

    if (nbytes < 0) {
      printf("error : CAN send error : %d , restart... \n", errno);
      return -1;
    }

    return nbytes;
  }

  private:
  std::string name_;
  int socket_flags_ = O_RDWR;
  int fd_ = -1;
};
