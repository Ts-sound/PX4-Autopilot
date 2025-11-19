# px4 remote pxh 使用fifo(named pipe)

* 将 px4 pxh 命令行终端通过fifo(named pipe)映射出来，方便远程调用。

## 设置参数

* 设置环境变量 `PX4_RUNPATH` ，如：`export PX4_RUNPATH=/temp/tong/px4/`
* 运行成功后，会创建两个fifo,如下：

```bash
tree /temp/tong/px4/
/temp/tong/px4/
`-- temp
    |-- px42remote_fifo # px4 -> remote
    `-- remote2px4_fifo # remote -> px4
```

## 测试

* 先打开接收端，再打开发送端

### 发送端

* 发送 px4 指令

```bash
cd /temp/tong/px4/temp
echo "commander status" > remote2px4_fifo
```

### 接收端

* 接收 px4 返回数据

```bash
cd /temp/tong/px4/temp
cat px42remote_fifo
```

* 成功后如下：

```bash
root@ac41c3b78c6c:/temp/tong/px4/temp# cat px42remote_fifo
commander status
INFO  [commander] Arm state: Standby
INFO  [commander] navigation mode: AUTO_LOITER
INFO  [commander] user intended navigation mode: AUTO_LOITER
INFO  [commander] in failsafe: no
commander: cycle: 78620 events, 350554us elapsed, 4.46us avg, min 1us max 118us 4.337us rms
commander: preflight check: 7862 events, 78237us elapsed, 9.95us avg, min 2us max 103us 3.048us rms
pxh>

```
