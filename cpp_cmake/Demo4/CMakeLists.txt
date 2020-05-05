# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (Demo4)
aux_source_directory(. DIR_SRCS)

add_executable(Demo4 main.cpp ${DIR_SRCS})
