# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (demo)

aux_source_directory(. DIR_SRCS)
# 指定生成目标

add_executable(test test.c ${DIR_SRCS})