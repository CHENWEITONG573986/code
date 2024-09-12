# 或者你所需要的最低版本
cmake_minimum_required(VERSION 3.10)

# 指定项目名
project(Car)

set(CMAKE_LINKER "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/11.2 2022.02/bin/arm-none-eabi-ld.exe")
set(CMAKE_C_COMPILER "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/11.2 2022.02/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/11.2 2022.02/bin/arm-none-eabi-g++.exe")

# 搜索头文件
include_directories(include)

# 搜索源文件
aux_source_directory(src SRC_SUB)
aux_source_directory(include SRC_INC)

# 生成可执行程序
add_executable(Car ${SRC_SUB} ${SRC_INC})