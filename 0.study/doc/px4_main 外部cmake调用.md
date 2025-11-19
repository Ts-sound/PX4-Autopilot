
```bash
# cmake版本限制
cmake_minimum_required(VERSION 3.15.0)

# 项目名称，cmake要求
project(PX4_Autopilot VERSION 1.0.0)


include(ExternalProject)

set(PX4_BUILD_OPTIONS
    -DBOARD=px4_t113_default
    -DCONFIG=px4_t113_default
    -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/px4_install
    # 添加其他需要的PX4配置选项
)

ExternalProject_Add(px4_external
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rd/px4
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/px4_build
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/px4_install

    # 配置命令
    CMAKE_ARGS
    ${PX4_BUILD_OPTIONS}
    -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    -DCMAKE_PREFIX_PATH=<INSTALL_DIR>

    # 构建选项
    BUILD_ALWAYS ON
    BUILD_IN_SOURCE FALSE

    # 安装步骤（可选）
    # INSTALL_COMMAND ""

    # 日志输出
    LOG_CONFIGURE TRUE
    LOG_BUILD TRUE
    LOG_INSTALL TRUE
)

set(3rdpartylib ${CMAKE_CURRENT_BINARY_DIR}/px4_build/platforms/posix/libpx4_main.so)
message("3rdpartylib: ${3rdpartylib}")

    # 生成动态库
    add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
    add_dependencies(${PROJECT_NAME} px4_external)

    # 指明依赖的库
    target_link_libraries(${PROJECT_NAME}
        ${3rdpartylib}
        -pthread)
    file(COPY include DESTINATION ${GOMROS_COMPLNENT_RUN})
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/px4_install/px4/bin DESTINATION ${GOMROS_COMPLNENT_RUN})
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/px4_install/px4/etc DESTINATION ${GOMROS_COMPLNENT_RUN})

    # 打包编译出结果
    install(TARGETS ${PROJECT_NAME} DESTINATION lib)
    install(FILES ${3rdpartylib} DESTINATION lib)
endif()

```
