# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (Demo1)

aux_source_directory(. DIR_SRCS) #aux_source_directory 在目录中查找所有源文件
# 指定生成目标

add_executable(Demo main.cpp ${DIR_SRCS})