# 或者你所需要的最低版本
cmake_minimum_required(VERSION 3.10)

# 指定项目名
project(Computer_room_reservation_system)

# 搜索头文件
include_directories(include)

# 搜索源文件
aux_source_directory(src SRC_SUB)

# 生成可执行程序
add_executable(Computer_room_reservation_system ${SRC_SUB})