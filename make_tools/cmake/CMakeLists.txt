# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.12)

# 项目信息
project(cmake)

# 是否使用 SUB2 库
option (USE_SUB2
        "Use sub2 on" OFF)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
        "${PROJECT_SOURCE_DIR}/config/config.h.in"
        "${PROJECT_SOURCE_DIR}/config/config.h"
)



# 是否加入 MathFunctions 库
if (USE_SUB2)
    include_directories ("${PROJECT_SOURCE_DIR}/sub/sub2")
    add_subdirectory (sub/sub2)
        set (EXTRA_LIBS ${EXTRA_LIBS} SUB2)
endif (USE_SUB2)

set(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./Inc DIR_INC)
aux_source_directory(./Src DIR_SRC)

# 添加 math 子目录
add_subdirectory(sub/sub1)

#指定生成目标
add_executable(cmaketest main.cpp TestClass.cpp TestClass.h Src/TestClassInSrc.cpp Inc/TestClassInSrc.h
        ${DIR_SRC}
        ${DIR_INC})

# 添加链接库
target_link_libraries(cmaketest SUB1 ${EXTRA_LIBS})