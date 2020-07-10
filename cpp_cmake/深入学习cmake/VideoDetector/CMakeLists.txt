# ===================================================================================
#  The OpenCV CMake configuration file
#
#  set: 设置变量
#
#  find_package： 用于到目录 {Packagename}_DIR 下面寻找 {Package}Config.cmake文件，然后
#                 执行该{Package}Config.cmake文件，如下所示：
#  find_package 使用方法:
#             <1> set(SupplyOpencv_DIR "D:/vs_nty/OPENCV_SUPPLY_32BIT")
#             <2> find_package(SupplyOpencv REQUIRED)
#                 该命令就会到${SupplyOpencv_DIR}目录下面找到 SupplyOpencvConfig.cmake文
#				  件，并且执行SupplyOpencvConfig.cmake。
#                 SupplyOpencvConfig.cmake如下：
#                 --------------------------------------------------------------------
#				  set(Flat "32")
#
#                 if(Flat EQUAL "32")
#					set(SupplyOpencv_DIR "D:/vs_nty/OPENCV_SUPPLY_32BIT")
#					set(SupplyOpencv_Include_Dirs  "D:/vs_nty/OPENCV_SUPPLY_32BIT")
#					set(SupplyOpencv_Libs "D:/vs_nty/OPENCV_SUPPLY_32BIT")
# 				  elseif(Flat MATCHES "^[0-9]{2}$")
#					message("there are no 63lib")
# 				  endif()
#                 --------------------------------------------------------------------
#                 然后就可以在此CmakeLists.txt中，引用SupplyOpencvConfig.cmake定义的变量，
#                 如下所示：
#
#
#                 include_directories( ${SupplyOpencv_Include_Dirs})
#                 link_directories(${SupplyOpencv_Libs})
#
#		
#    
#======================================================================================


cmake_minimum_required(VERSION 3.5)

project(VideoDetector LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(OpenCV_DIR "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86")
set(SupplyOpencv_DIR "D:/vs_nty/OPENCV_SUPPLY_32BIT")

set(OpenCV_INCLUDE_DIRS  "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/include" "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/include/opencv2/opencv2")
set(OpenCV_LIBS "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/x86/mingw/bin")


#set(Supply_LIBS "D:/vs_nty/NTY_IMG_PROCESS/dll")


find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIBS})


find_package(SupplyOpencv REQUIRED)
include_directories( ${SupplyOpencv_Include_Dirs})
link_directories(${SupplyOpencv_Libs})
#link_libraries(${Supply_LIBS})

find_package(Qt5Core)

add_executable(VideoDetector
  main.cpp
  meanshift.h
)
target_link_libraries(VideoDetector Qt5::Core)
target_link_libraries(VideoDetector  ${OpenCV_LIBS} )
target_link_libraries(VideoDetector  ${SupplyOpencv_Libs}/libOPENCV_SUPPLY_32BIT.dll )
