cmake_minimum_required(VERSION 3.5)

project(VideoDetector LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(OpenCV_DIR "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86")
set(OpenCV_INCLUDE_DIRS  "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/include" "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/include/opencv2/opencv2")
set(OpenCV_LIBS "D:/vs_nty/OpenCV-MinGW-Build-OpenCV-4.1.0_x86/x86/mingw/bin")
set(Supply_LIBS "D:/vs_nty/NTY_IMG_PROCESS/dll")

include_directories( ${OpenCV_INCLUDE_DIRS} )


find_package( OpenCV REQUIRED )
link_directories(${OpenCV_LIBS})


include_directories("D:/vs_nty/OPENCV_SUPPLY_32BIT")
link_directories(${Supply_LIBS})
#link_libraries(${Supply_LIBS})

find_package(Qt5Core)

add_executable(VideoDetector
  main.cpp
)
target_link_libraries(VideoDetector Qt5::Core)
target_link_libraries(VideoDetector  ${OpenCV_LIBS} )
target_link_libraries(VideoDetector  ${Supply_LIBS}/libOPENCV_SUPPLY_32BIT.dll )
