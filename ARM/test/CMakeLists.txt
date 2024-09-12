# 或者你所需要的最低版本
cmake_minimum_required(VERSION 3.10)
set(EXT "")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER "arm-none-eabi-gcc.exe")

set(CMAKE_CXX_COMPILER "arm-none-eabi-g++.exe")

set(CMAKE_LINKER arm-none-eabi-ld.exe)



set(CMAKE_SYSTEM_PROCESSOR arm)

project(hello-aarch64)

set(src main.c)

add_executable(hello-aarch64 ${src})