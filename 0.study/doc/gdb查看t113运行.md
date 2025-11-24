# gdb查看t113运行

## gdb 堆栈打印

```bash
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
__GI___libc_read (nbytes=1, buf=0x7fa57ecdcb23 <_IO_2_1_stdin_+131>, fd=0) at ../sysdeps/unix/sysv/linux/read.c:26
26      ../sysdeps/unix/sysv/linux/read.c: No such file or directory.
(gdb) thread apply all bt

Thread 16 (Thread 0x7fa57aa01a40 (LWP 10276) "mavlink_rcv_if0"):
#0  0x00007fa57ebdabcf in __GI___poll (fds=fds@entry=0x7fa57a9ff078, nfds=nfds@entry=1, timeout=timeout@entry=10) at ../sysdeps/unix/sysv/linux/poll.c:29
#1  0x00005595cc04259b in poll (__timeout=10, __nfds=1, __fds=0x7fa57a9ff078) at /usr/include/x86_64-linux-gnu/bits/poll2.h:39
#2  MavlinkReceiver::run (this=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/mavlink/mavlink_receiver.cpp:3120
#3  0x00005595cc043d6d in MavlinkReceiver::start_trampoline (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/mavlink/mavlink_receiver.cpp:3484
#4  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#5  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 15 (Thread 0x7fa57aa18380 (LWP 10274) "mavlink_if0"):
#0  0x00007fa57eba77f8 in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fa57aa178d0, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007fa57ebac677 in __GI___nanosleep (req=req@entry=0x7fa57aa178d0, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
#2  0x00007fa57ebddf2f in usleep (useconds=<optimized out>) at ../sysdeps/posix/usleep.c:31
#3  0x00005595cc0170bc in Mavlink::task_main (this=0x7fa54c000b70, argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/mavlink/mavlink_main.cpp:2207
#4  0x00005595cc01aacb in Mavlink::start_helper (argc=11, argv=0x7fa558009770) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/mavlink/mavlink_main.cpp:2709
#5  0x00005595cc125a2d in entry_adapter (ptr=0x7fa558009750) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#6  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#7  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 14 (Thread 0x7fa57aa27640 (LWP 10268) "commander"):
#0  0x00007fa57eba77f8 in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fa57aa26d40, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007fa57ebac677 in __GI___nanosleep (req=req@entry=0x7fa57aa26d40, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
#2  0x00007fa57ebddf2f in usleep (useconds=<optimized out>) at ../sysdeps/posix/usleep.c:31
#3  0x00005595cbf774b3 in Commander::run (this=0x7fa548000b70) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/commander/Commander.cpp:1841
#4  0x00005595cbf7adbd in ModuleBase<Commander>::run_trampoline (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/include/px4_platform_common/module.h:180
#5  0x00005595cc125a2d in entry_adapter (ptr=0x7fa558008e00) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#6  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#7  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 13 (Thread 0x7fa57aa3c4c0 (LWP 10135) "navigator"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x7fa57aa3b9a0, op=137, expected=0, futex_word=0x7fa57aa3ba00) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x7fa57aa3b9a0, clockid=0, expected=0, futex_word=0x7fa57aa3ba00) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57aa3ba00, expected=expected@entry=0, clockid=clockid@entry=1, abstime=abstime@entry=0x7fa57aa3b9a0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55e9b in __pthread_cond_wait_common (abstime=0x7fa57aa3b9a0, clockid=1, mutex=0x7fa57aa3b9b0, cond=0x7fa57aa3b9d8) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_timedwait64 (cond=0x7fa57aa3b9d8, mutex=0x7fa57aa3b9b0, abstime=0x7fa57aa3b9a0) at ./nptl/pthread_cond_wait.c:652
#5  0x00005595cc125f57 in px4_sem_timedwait (s=0x7fa57aa3b9b0, abstime=0x7fa57aa3b9a0) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:137
#6  0x00005595cc11d4bb in px4_poll (fds=0x7fa57aa3bb70, nfds=<optimized out>, timeout=1000) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/lib/cdev/posix/cdev_platform.cpp:405
#7  0x00005595cc06d99e in Navigator::run (this=0x7fa554000b70) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/navigator/navigator_main.cpp:177
#8  0x00005595cc06d20e in ModuleBase<Navigator>::run_trampoline (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/include/px4_platform_common/module.h:180
#9  0x00005595cc125a2d in entry_adapter (ptr=0x7fa558004f30) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#10 0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#11 0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 12 (Thread 0x7fa57aa45640 (LWP 10132) "wq:rate_ctrl"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa57aa44d58) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa57aa44d58) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57aa44d58, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa57aa44d08, cond=0x7fa57aa44d30) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa57aa44d30, mutex=0x7fa57aa44d08) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa57aa44d08) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc1277f8 in px4::WorkQueue::Run (this=this@entry=0x7fa57aa44c90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueue.cpp:178
#7  0x00005595cc127e4e in px4::WorkQueueRunner (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:237
#8  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#9  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 11 (Thread 0x7fa57aa4e640 (LWP 10131) "wq:manager"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa57aa4dd58) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa57aa4dd58) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57aa4dd58, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa57aa4dd08, cond=0x7fa57aa4dd30) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa57aa4dd30, mutex=0x7fa57aa4dd08) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa57aa4dd08) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc1277f8 in px4::WorkQueue::Run (this=this@entry=0x7fa57aa4dc90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueue.cpp:178
#7  0x00005595cc127e4e in px4::WorkQueueRunner (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:237
#8  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#9  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100


Thread 10 (Thread 0x7fa57aa56640 (LWP 10126) "wq:hp_default"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa57aa55d58) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa57aa55d58) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57aa55d58, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa57aa55d08, cond=0x7fa57aa55d30) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa57aa55d30, mutex=0x7fa57aa55d08) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa57aa55d08) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc1277f8 in px4::WorkQueue::Run (this=this@entry=0x7fa57aa55c90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueue.cpp:178
#7  0x00005595cc127e4e in px4::WorkQueueRunner (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:237
#8  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#9  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 9 (Thread 0x7fa57aa5e640 (LWP 10123) "wq:ttyS5"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa57aa5dd5c) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa57aa5dd5c) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57aa5dd5c, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa57aa5dd08, cond=0x7fa57aa5dd30) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa57aa5dd30, mutex=0x7fa57aa5dd08) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa57aa5dd08) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc1277f8 in px4::WorkQueue::Run (this=this@entry=0x7fa57aa5dc90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueue.cpp:178
#7  0x00005595cc127e4e in px4::WorkQueueRunner (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:237
#8  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#9  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 8 (Thread 0x7fa57f025640 (LWP 10108) "wq:lp_default"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa57f024d58) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa57f024d58) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa57f024d58, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa57f024d08, cond=0x7fa57f024d30) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa57f024d30, mutex=0x7fa57f024d08) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa57f024d08) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc1277f8 in px4::WorkQueue::Run (this=this@entry=0x7fa57f024c90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueue.cpp:178
#7  0x00005595cc127e4e in px4::WorkQueueRunner (context=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:237
#8  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#9  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 7 (Thread 0x7fa57aa96ac0 (LWP 10105) "dataman"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x5595cc2a5494 <g_work_queued_sema+84>) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x5595cc2a5494 <g_work_queued_sema+84>) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x5595cc2a5494 <g_work_queued_sema+84>, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x5595cc2a5440 <g_work_queued_sema>, cond=0x5595cc2a5468 <g_work_queued_sema+40>) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x5595cc2a5468 <g_work_queued_sema+40>, mutex=0x5595cc2a5440 <g_work_queued_sema>) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x5595cc2a5440 <g_work_queued_sema>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cbf8f99a in task_main (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/dataman/dataman.cpp:1029
#7  task_main (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/modules/dataman/dataman.cpp:941
#8  0x00005595cc125a2d in entry_adapter (ptr=0x7fa570002550) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#9  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#10 0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 6 (Thread 0x7fa57aaaba40 (LWP 10015) "wq:manager"):
#0  __futex_abstimed_wait_common64 (private=0, cancel=true, abstime=0x0, op=393, expected=0, futex_word=0x7fa56c000c94) at ./nptl/futex-internal.c:57
#1  __futex_abstimed_wait_common (cancel=true, private=0, abstime=0x0, clockid=0, expected=0, futex_word=0x7fa56c000c94) at ./nptl/futex-internal.c:87
#2  __GI___futex_abstimed_wait_cancelable64 (futex_word=futex_word@entry=0x7fa56c000c94, expected=expected@entry=0, clockid=clockid@entry=0, abstime=abstime@entry=0x0, private=private@entry=0) at ./nptl/futex-internal.c:139
#3  0x00007fa57eb55a41 in __pthread_cond_wait_common (abstime=0x0, clockid=0, mutex=0x7fa56c000c40, cond=0x7fa56c000c68) at ./nptl/pthread_cond_wait.c:503
#4  ___pthread_cond_wait (cond=0x7fa56c000c68, mutex=0x7fa56c000c40) at ./nptl/pthread_cond_wait.c:627
#5  0x00005595cc125e3c in px4_sem_wait (s=0x7fa56c000c40) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_sem.cpp:89
#6  0x00005595cc127ab0 in BlockingQueue<px4::wq_config_t const*, 1ul>::pop (this=0x7fa56c000be0) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/src/include/containers/BlockingQueue.hpp:67
#7  px4::WorkQueueManagerRun () at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/px4_work_queue/WorkQueueManager.cpp:264
#8  0x00005595cc125a2d in entry_adapter (ptr=0x5595cdd31c20) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#9  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#10 0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 5 (Thread 0x7fa57aabb640 (LWP 10014) "wkr_hrt"):
#0  0x00007fa57eba77f8 in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fa57aabadd0, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007fa57ebac677 in __GI___nanosleep (req=req@entry=0x7fa57aabadd0, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
--Type <RET> for more, q to quit, c to continue without paging--
#2  0x00007fa57ebddf2f in usleep (useconds=useconds@entry=2282) at ../sysdeps/posix/usleep.c:31
#3  0x00005595cc12d78e in hrt_work_process () at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/hrt_thread.c:232
#4  work_hrtthread (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/hrt_thread.c:276
#5  0x00005595cc125a2d in entry_adapter (ptr=0x5595cdd31a00) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#6  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#7  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 4 (Thread 0x7fa57f034640 (LWP 10013) "lpwork"):
#0  0x00007fa57eba77f8 in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fa57f033e00, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007fa57ebac677 in __GI___nanosleep (req=req@entry=0x7fa57f033e00, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
#2  0x00007fa57ebddf2f in usleep (useconds=<optimized out>) at ../sysdeps/posix/usleep.c:31
#3  0x00005595cc12dc52 in work_process (wqueue=wqueue@entry=0x5595cc2abcb8 <g_work+24>, lock_id=lock_id@entry=1) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/work_thread.c:194
#4  0x00005595cc12dcbd in work_lpthread (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/work_thread.c:305
#5  0x00005595cc125a2d in entry_adapter (ptr=0x5595cdd31890) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#6  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#7  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 3 (Thread 0x7fa57f043640 (LWP 10012) "hpwork"):
#0  0x00007fa57eba77f8 in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fa57f042e00, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
#1  0x00007fa57ebac677 in __GI___nanosleep (req=req@entry=0x7fa57f042e00, rem=rem@entry=0x0) at ../sysdeps/unix/sysv/linux/nanosleep.c:25
#2  0x00007fa57ebddf2f in usleep (useconds=<optimized out>) at ../sysdeps/posix/usleep.c:31
#3  0x00005595cc12dc52 in work_process (wqueue=wqueue@entry=0x5595cc2abca0 <g_work>, lock_id=lock_id@entry=0) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/work_thread.c:194
#4  0x00005595cc12dc9a in work_hpthread (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/common/work_queue/work_thread.c:279
#5  0x00005595cc125a2d in entry_adapter (ptr=0x5595cdd31720) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/tasks.cpp:98
#6  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#7  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

Thread 2 (Thread 0x7fa57eabc640 (LWP 10011) "px4"):
#0  0x00007fa57ebdabcf in __GI___poll (fds=0x7fa574000ee0, nfds=1, timeout=-1) at ../sysdeps/unix/sysv/linux/poll.c:29
#1  0x00005595cc12cd4e in poll (__timeout=-1, __nfds=1, __fds=<optimized out>) at /usr/include/x86_64-linux-gnu/bits/poll2.h:39
#2  px4_daemon::Server::_server_main (this=0x7fffb5e9dbf0) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_daemon/server.cpp:150
#3  0x00005595cc12d30d in px4_daemon::Server::_server_main_trampoline (self=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_daemon/server.cpp:120
#4  0x00007fa57eb56ac3 in start_thread (arg=<optimized out>) at ./nptl/pthread_create.c:442
#5  0x00007fa57ebe7a04 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:100

--Type <RET> for more, q to quit, c to continue without paging--
Thread 1 (Thread 0x7fa57eabd740 (LWP 10010) "px4"):
#0  __GI___libc_read (nbytes=1, buf=0x7fa57ecdcb23 <_IO_2_1_stdin_+131>, fd=0) at ../sysdeps/unix/sysv/linux/read.c:26
#1  __GI___libc_read (fd=0, buf=0x7fa57ecdcb23 <_IO_2_1_stdin_+131>, nbytes=1) at ../sysdeps/unix/sysv/linux/read.c:24
#2  0x00007fa57eb4ec36 in _IO_new_file_underflow (fp=0x7fa57ecdcaa0 <_IO_2_1_stdin_>) at ./libio/libioP.h:947
#3  0x00007fa57eb4fd96 in __GI__IO_default_uflow (fp=0x7fa57ecdcaa0 <_IO_2_1_stdin_>) at ./libio/libioP.h:947
#4  0x00007fa57eb49a98 in _IO_getc (fp=0x7fa57ecdcaa0 <_IO_2_1_stdin_>) at ./libio/getc.c:40
#5  0x00005595cc12b357 in getchar () at /usr/include/x86_64-linux-gnu/bits/stdio.h:49
#6  px4_daemon::Pxh::run_pxh (this=this@entry=0x7fffb5e9dc90) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/px4_daemon/pxh.cpp:312

#7  0x00005595cbf3f799 in main (argc=<optimized out>, argv=<optimized out>) at /opt/tong/ws/gomros2-device2/devicelayer/px4/PX4_Autopilot/3rd/px4/platforms/posix/src/px4/common/main.cpp:407
(gdb)
(gdb)
(gdb)
```

```bash
pxh> work_queue status

Work Queue: 5  threads                          RATE        INTERVAL
|__ 1) wq:rate_ctrl
|   |__ 1) control_allocator                  7.6 Hz       131224 us
|   |__ 2) mc_rate_control                    0.0 Hz            0 us
|   \__ 3) vehicle_angular_velocity          38.0 Hz        26319 us
|__ 2) wq:nav_and_controllers
|   |__ 1) ekf2_selector                      0.0 Hz            0 us
|   |__ 2) flight_mode_manager                0.0 Hz            0 us
|   |__ 3) land_detector                      7.6 Hz       131221 us
|   |__ 4) mc_att_control                     0.0 Hz            0 us
|   |__ 5) mc_hover_thrust_estimator          0.0 Hz            0 us
|   |__ 6) mc_pos_control                     3.8 Hz       262200 us
|   |__ 7) sensors                           38.0 Hz        26319 us
|   |__ 8) vehicle_acceleration               0.0 Hz            0 us
|   |__ 9) vehicle_air_data                   7.6 Hz       131221 us
|   |__10) vehicle_gps_position               1.3 Hz       784611 us
|   \__11) vehicle_magnetometer               7.6 Hz       131221 us
|__ 3) wq:hp_default
|   |__ 1) manual_control                     1.9 Hz       524257 us
|   \__ 2) rc_update                          0.0 Hz            0 us
|__ 4) wq:ttyS5
|   \__ 1) rc_input                         242.9 Hz         4117 us (4000 us)
\__ 5) wq:lp_default
    \__ 1) load_mon                           2.0 Hz       499912 us (500000 us)
```

## urgb

```bash
pxh> uorb status
TOPIC NAME              INST #SUB #Q SIZE PATH
actuator_armed             0    5  1   16 /obj/actuator_armed0
actuator_motors            0    0  1   72 /obj/actuator_motors0
actuator_servos            0    0  1   48 /obj/actuator_servos0
actuator_servos_trim       0    0  1   40 /obj/actuator_servos_trim0
control_allocator_status   0    0  1   56 /obj/control_allocator_status0
control_allocator_status   1    0  1   56 /obj/control_allocator_status1
cpuload                    0    3  1   16 /obj/cpuload0
estimator_selector_status  0    2  1  160 /obj/estimator_selector_status0
event                      0    1 16   40 /obj/event0
failsafe_flags             0    0  1   88 /obj/failsafe_flags0
failure_detector_status    0    1  1   24 /obj/failure_detector_status0
health_report              0    1  1   64 /obj/health_report0
led_control                0    0  8   16 /obj/led_control0
log_message                0    0  4  136 /obj/log_message0
manual_control_setpoint    0    4  1   64 /obj/manual_control_setpoint0
mavlink_log                0    1  8  136 /obj/mavlink_log0
parameter_update           0   22  1   40 /obj/parameter_update0
position_setpoint_triplet  0    3  1  224 /obj/position_setpoint_triplet0
rate_ctrl_status           0    0  1   24 /obj/rate_ctrl_status0
rtl_time_estimate          0    2  1   24 /obj/rtl_time_estimate0
sensor_combined            0    0  1   48 /obj/sensor_combined0
sensor_preflight_mag       0    1  1   16 /obj/sensor_preflight_mag0
sensor_selection           0    6  1   16 /obj/sensor_selection0
sensors_status_imu         0    2  1   96 /obj/sensors_status_imu0
takeoff_status             0    1  1   16 /obj/takeoff_status0
telemetry_status           0    1  1   88 /obj/telemetry_status0
transponder_report         0    2 32   80 /obj/transponder_report0
tune_control               0    0  4   24 /obj/tune_control0
vehicle_acceleration       0    1  1   32 /obj/vehicle_acceleration0
vehicle_air_data           0    5  1   40 /obj/vehicle_air_data0
vehicle_angular_velocity   0    5  1   40 /obj/vehicle_angular_velocity0
vehicle_attitude           0    6  1   56 /obj/vehicle_attitude0
vehicle_command            0    6  8   56 /obj/vehicle_command0
vehicle_control_mode       0    6  1   24 /obj/vehicle_control_mode0
vehicle_global_position    0    7  1   64 /obj/vehicle_global_position0
vehicle_gps_position       0    5  1  128 /obj/vehicle_gps_position0
vehicle_land_detected      0    5  1   24 /obj/vehicle_land_detected0
vehicle_local_position     0   17  1  168 /obj/vehicle_local_position0
vehicle_magnetometer       0    0  1   40 /obj/vehicle_magnetometer0
vehicle_odometry           0    0  1  112 /obj/vehicle_odometry0
vehicle_status             0   18  1   72 /obj/vehicle_status0
wind                       0    2  1   48 /obj/wind0
```
