# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (jsonTest)

include_directories(C:/work/gitwork/cpp/cpp_cmake/Demo5/include/)
LINK_DIRECTORIES(C:/work/gitwork/cpp/cpp_cmake/Demo5/lib/)

add_executable(jsonTest testjson.cpp)
TARGET_LINK_LIBRARIES(jsonTest libjsoncpp.a)
