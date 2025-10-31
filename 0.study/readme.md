
# 资料

- T113资料：https://guanglun.github.io/gldrone/gldrone-t113
  - https://github.com/guanglun/PX4-Autopilot

- 其他相关视频资料：【年轻人第一款Linux飞控-哔哩哔哩】 https://b23.tv/QJzYvBm
  - https://blog.csdn.net/weixin_42037083?type=blog
  - https://blog.csdn.net/weixin_55944949/article/details/130848009?spm=1001.2014.3001.5502

## 设置2.4G

热点2.4G/5G切换
进入终端修改脚本vim /etc/init.d/S45wifi_ap
![Alt text](./assets/img/wlan_set.png)

"hostapd"后面添加"_5g"为使用5G热点，不添加为使用2.4G热点
飞控板的热点WIFI：DRONE5G(密码：12345678)

Linux用户名：root 密码：root
串口4为Linux调试串口，波特率115200

## 系统相关信息

```bash
# armv7l架构（arm32）,  两核心，112M内存 ， 100M硬盘

root@gldz:~$ cat /etc/os-release
NAME=Buildroot
VERSION=-g14ad2dcb
ID=buildroot
VERSION_ID=2023.02
PRETTY_NAME="Buildroot 2023.02"

root@gldz:~$ uname -a
Linux gldz 6.8.0 #1 SMP Wed Apr 16 18:09:06 CST 2025 armv7l GNU/Linux

root@gldz:~$ df -h
Filesystem                Size      Used Available Use% Mounted on
ubi0:rootfs             100.7M     52.2M     48.5M  52% /
devtmpfs                 47.7M         0     47.7M   0% /dev
tmpfs                    56.2M         0     56.2M   0% /dev/shm
tmpfs                    56.2M     40.0K     56.2M   0% /tmp
tmpfs                    56.2M     28.0K     56.2M   0% /run


```

## 控制原理图

```bash
T113(linux) --PWM--> 电机驱动版(stm32)  ----> 电机1
   |                                   |
   |                                   |----> 电机2
   |                                   |
   |                                   |----> 电机3
   |                                   |
   |                                   |----> 电机4
   |
   --- spi/i2c --> IMU/磁罗盘/气压计
   |
   |
   --- 串口转SBUS --> 接收器（手柄遥控器）
   |
   |
   --- wifi --> (ssh,QGC地面站)

```

## T113 对PX4 修改分析

### a. 添加 px4_t113 编译对象

- .ci/Jenkinsfile-compile
- .github/workflows/compile_linux.yml

```diff
diff --git a/.ci/Jenkinsfile-compile b/.ci/Jenkinsfile-compile
index 2936194886..1b0d73eb4b 100644
--- a/.ci/Jenkinsfile-compile
+++ b/.ci/Jenkinsfile-compile
@@ -16,7 +16,7 @@ pipeline {
           ]

           def armhf_builds = [
-            target: ["beaglebone_blue_default", "emlid_navio2_default", "px4_raspberrypi_default", "scumaker_pilotpi_default"],
+            target: ["beaglebone_blue_default", "emlid_navio2_default", "px4_raspberrypi_default", "px4_t113_default", "scumaker_pilotpi_default"],
             image: docker_images.armhf,
             archive: false
           ]
diff --git a/.github/workflows/compile_linux.yml b/.github/workflows/compile_linux.yml
index d14b533475..f3ab3bd2c4 100644
--- a/.github/workflows/compile_linux.yml
+++ b/.github/workflows/compile_linux.yml
@@ -18,6 +18,7 @@ jobs:
           beaglebone_blue_default,
           emlid_navio2_default,
           px4_raspberrypi_default,
+          px4_t113_default,
           scumaker_pilotpi_default,
           ]
```

### b. 添加 t113 板子 驱动

* `boards/px4/t113/*`
  * pwm_out 实现  `class NavioSysfsPWMOut : public PWMOutBase`
  * i2c/spi 配置

```c++

/// i2c
constexpr px4_i2c_bus_t px4_i2c_buses[I2C_BUS_MAX_BUS_ITEMS] = {
initI2CBusInternal(2),
initI2CBusExternal(0),
initI2CBusExternal(1)};

/// spi
constexpr px4_spi_bus_t px4_spi_buses[SPI_BUS_MAX_BUS_ITEMS] = {
initSPIBus(1,
{initSPIDevice(DRV_ACC_DEVTYPE_BMI088,  0),
initSPIDevice(DRV_GYR_DEVTYPE_BMI088,  1),
}),};

```

* `platforms/posix/cmake/Toolchain-arm-none-linux-gnueabihf.cmake`
  * 对应板子的交叉编译cmake文件
* `posix-configs/t113/*`
  * 添加 t113 px4的相关配置文件
* `src/drivers/auxio/*`
  * 遥控器相关驱动
* `src/modules/battery_status/battery_status.cpp`
  * 电池数据获取修改
* `src/modules/commander/commander_helper.cpp`
  * 屏蔽led灯输出相关代码，应该是没有led运行会报错
* src/modules/mavlink/streams/DISTANCE_SENSOR.hpp
  * 加了打印


## 运行

```bash
CPU:  11% usr  48% sys   0% nic  40% idle   0% io   0% irq   0% sirq
Load average: 1.82 1.48 0.74 3/102 22781
  PID  PPID USER     STAT   VSZ %VSZ %CPU COMMAND
  158     1 root     S    27036  23%  26% ./bin/px4 -s px4_mc.config -d
```
