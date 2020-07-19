cmake_minimum_required(VERSION 3.5)

project(DigitalFactory LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

find_package(Qt5 COMPONENTS Widgets Sql  REQUIRED)


set(RCC_FILES resource.qrc)
#file(GLOB_RECURSE RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_add_resources(QRC_FILES ${RCC_FILES})


set(POSTGRESQL_DIR "C:/myinstalled/PostGresql")
include_directories(${POSTGRESQL_DIR}/include)
link_directories(${POSTGRESQL_DIR}/lib)

#set(MYSQL_DIR "C:/work/mysql-5.7.27-winx64")
#include_directories(${MYSQL_DIR}/include)
#link_directories(${MYSQL_DIR}/lib)

if(ANDROID)
    add_library(DigitalFactory SHARED
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        )
else()
    add_executable(DigitalFactory
        main.cpp
        mainwindow.cpp
        mainwindow.h
        meanshift.h
        meanshift.cpp

        postsqlsdk.h
        postsqlsdk.cpp

        mainwindow.ui
        ui_loginform.h
        loginform.h
        loginform.ui
        ${QRC_FILES}
        )
endif()

target_link_libraries(DigitalFactory PRIVATE Qt5::Widgets Qt5::Sql )
target_link_libraries(DigitalFactory PRIVATE  ${POSTGRESQL_DIR}/lib/libpq.lib)
#target_link_libraries(DigitalFactory PRIVATE  ${MYSQL_DIR}/lib/libmysql.lib)
