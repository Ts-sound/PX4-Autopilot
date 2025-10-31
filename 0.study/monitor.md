
```bash
root@gldz:~/px4/bin$ ./px4-work_queue status

Work Queue: 8  threads                          RATE        INTERVAL
|__ 1) wq:rate_ctrl
|   |__ 1) control_allocator                400.0 Hz         2500 us
|   |__ 2) mc_rate_control                  400.0 Hz         2500 us
|   \__ 3) vehicle_angular_velocity         400.0 Hz         2500 us
|__ 2) wq:SPI1
|   |__ 1) bmi088_accel                     400.0 Hz         2500 us (2500 us)
|   \__ 2) bmi088_gyro                      400.0 Hz         2500 us (2500 us)
|__ 3) wq:I2C2
|   |__ 1) bmp388                            23.1 Hz        43300 us (43300 us)
|   \__ 2) ist8310                           46.2 Hz        21649 us
|__ 4) wq:nav_and_controllers
|   |__ 1) ekf2_selector                    299.3 Hz         3341 us
|   |__ 2) flight_mode_manager               50.0 Hz        20000 us
|   |__ 3) land_detector                    100.0 Hz        10000 us
|   |__ 4) mc_att_control                   200.0 Hz         5000 us
|   |__ 5) mc_hover_thrust_estimator        100.0 Hz        10000 us
|   |__ 6) mc_pos_control                   100.0 Hz        10000 us
|   |__ 7) sensors                          200.0 Hz         5000 us
|   |__ 8) vehicle_acceleration             200.0 Hz         5000 us
|   |__ 9) vehicle_air_data                  23.1 Hz        43298 us
|   |__10) vehicle_gps_position               3.3 Hz       300063 us
|   \__11) vehicle_magnetometer              46.2 Hz        21649 us
|__ 5) wq:INS0
|   |__ 1) ekf2                             200.0 Hz         5000 us
|   \__ 2) vehicle_imu                      200.0 Hz         5000 us
|__ 6) wq:hp_default
|   |__ 1) auxio                            400.0 Hz         2500 us
|   |__ 2) manual_control                     5.0 Hz       200014 us
|   \__ 3) rc_update                          0.0 Hz            0 us
|__ 7) wq:ttyS5
|   \__ 1) rc_input                         250.0 Hz         4000 us (4000 us)
\__ 8) wq:lp_default
    \__ 1) load_mon                           2.0 Hz       499997 us (500000 us)
```




很好！从你的 `px4-work_queue status` 输出可以看到当前 PX4 系统运行的所有模块及其调度状态。让我为你详细解析：

## 当前运行的 PX4 模块分析

### 1. **高速控制线程 (wq:rate_ctrl)**
- `control_allocator` - 控制分配器 (400Hz)
- `mc_rate_control` - 多旋翼速率控制 (400Hz)
- `vehicle_angular_velocity` - 角速度处理 (400Hz)

### 2. **SPI1 传感器线程**
- `bmi088_accel` - BMI088 加速度计驱动 (400Hz)
- `bmi088_gyro` - BMI088 陀螺仪驱动 (400Hz)

### 3. **I2C2 传感器线程**
- `bmp388` - BMP388 气压计驱动 (23.1Hz)
- `ist8310` - IST8310 磁力计驱动 (46.2Hz)

### 4. **核心导航与控制线程 (wq:nav_and_controllers)**
- `ekf2_selector` - EKF2 选择器 (299.3Hz)
- `flight_mode_manager` - 飞行模式管理 (50Hz)
- `land_detector` - 着陆检测 (100Hz)
- `mc_att_control` - 姿态控制 (200Hz)
- `mc_hover_thrust_estimator` - 悬停推力估计 (100Hz)
- `mc_pos_control` - 位置控制 (100Hz)
- `sensors` - 传感器数据处理 (200Hz)
- `vehicle_acceleration` - 加速度处理 (200Hz)
- `vehicle_air_data` - 大气数据 (23.1Hz)
- `vehicle_gps_position` - GPS 位置处理 (3.3Hz)
- `vehicle_magnetometer` - 磁力计处理 (46.2Hz)

### 5. **惯性导航线程 (wq:INS0)**
- `ekf2` - 扩展卡尔曼滤波器 (200Hz)
- `vehicle_imu` - IMU 数据处理 (200Hz)

### 6. **高优先级默认线程**
- `auxio` - 辅助IO (400Hz)
- `manual_control` - 手动控制 (5Hz)
- `rc_update` - RC 更新 (当前未运行)

### 7. **串口输入线程 (wq:ttyS5)**
- `rc_input` - RC 输入 (250Hz)

### 8. **低优先级默认线程**
- `load_mon` - 负载监控 (2Hz)

## 系统状态评估

✅ **系统运行正常**，所有关键模块都在运行：
- 传感器驱动正常 (BMI088, BMP388, IST8310)
- 导航滤波正常 (EKF2)
- 控制算法正常 (姿态/位置控制)
- 飞行管理正常 (模式管理, 着陆检测)

## 进一步监控建议

```bash
# 查看具体模块输出
./px4-listener vehicle_status          # 查看飞行状态
./px4-listener estimator_status        # 查看 EKF 状态
./px4-listener sensor_combined         # 查看传感器融合数据
./px4-listener vehicle_attitude        # 查看姿态数据
```

你的 PX4 系统运行状态良好，所有必要的模块都在正常调度运行！
