cmake_minimum_required(VERSION 3.5)

project(Freedom LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR C:/opencv/build)
set(OpenCV_INCLUDE_DIRS  C:/opencv/build/include)
set(OpenCV_LIBS C:/opencv/build/x64/vc15/lib)


# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets OpenCV  REQUIRED)

if(ANDROID)
  add_library(Freedom SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(Freedom
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
endif()

include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(Freedom PRIVATE Qt5::Widgets)
target_link_libraries(Freedom  ${OpenCV_LIBS})
