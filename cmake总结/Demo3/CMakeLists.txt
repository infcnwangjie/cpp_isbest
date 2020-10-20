# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (Demo1)
include_directories(E:/git/cpp/cpp_cmake/Demo3/libs)
LINK_DIRECTORIES(E:/git/cpp/cpp_cmake/Demo3/libs)

aux_source_directory(. DIR_SRCS)

add_executable(Demo main.cpp ${DIR_SRCS})

TARGET_LINK_LIBRARIES(Demo libadd.dll) #静态库必须写全 动态库可以写简称如add