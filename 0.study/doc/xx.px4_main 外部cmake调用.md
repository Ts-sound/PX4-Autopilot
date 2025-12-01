
```bash
# cmake版本限制
cmake_minimum_required(VERSION 3.15.0)

# 项目名称，cmake要求
project(test VERSION 1.0.0)


# toolchain , build
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
    # INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/px4_install

    # 配置命令
    CMAKE_ARGS
    ${PX4_BUILD_OPTIONS}
    -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    # -DCMAKE_PREFIX_PATH=<INSTALL_DIR>
    "$<$<BOOL:${CMAKE_TOOLCHAIN_FILE}>:-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}>"

    # 构建选项
    BUILD_ALWAYS ON
    BUILD_IN_SOURCE FALSE

    # 安装步骤（可选）
    INSTALL_COMMAND ""

    # 日志输出
    LOG_CONFIGURE TRUE
    LOG_BUILD TRUE
    LOG_INSTALL TRUE
)

set(3rdpartylib ${CMAKE_CURRENT_BINARY_DIR}/px4_build/platforms/posix/libpx4_main.so)
message("3rdpartylib: ${3rdpartylib}")

# 查找项目本身的源码
file(GLOB_RECURSE SRC_FILES "impl/*.c" "impl/*.cc" "impl/*.cpp")


add_custom_target(CopyExternalFiles
    COMMAND ${CMAKE_COMMAND} -E echo "Starting file copy..."
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_BINARY_DIR}/px4_build/bin
    ${GOMROS_COMPLNENT_RUN}/bin
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_BINARY_DIR}/px4_build/etc
    ${GOMROS_COMPLNENT_RUN}/etc
    DEPENDS px4_external
    COMMENT "Copying files px4_external"
)

# 生成动态库
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
add_dependencies(${PROJECT_NAME} px4_external CopyExternalFiles)



# 指明依赖的库
target_link_libraries(${PROJECT_NAME}  ${3rdpartylib}
    -pthread)

# 将include复制到run目录中，便于编译调试
file(COPY include DESTINATION ${GOMROS_COMPLNENT_RUN})

# 打包include
install(DIRECTORY include DESTINATION .)

# 打包编译出结果
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/px4_build/bin DESTINATION .
    FILE_PERMISSIONS
    OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_WRITE GROUP_EXECUTE
    WORLD_READ WORLD_WRITE WORLD_EXECUTE
)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/px4_build/etc DESTINATION .)
install(FILES ${3rdpartylib} DESTINATION lib)
# endif()


```
