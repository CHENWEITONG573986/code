# 或者你所需要的最低版本
cmake_minimum_required(VERSION 3.10)

# 指定项目名
project(SpeechSystem)

# 搜索源文件
aux_source_directory(src SRC_SUB)

# 搜索头文件
include_directories(include)

# 生成可执行程序
add_executable(SpeechSystem ${SRC_SUB})
