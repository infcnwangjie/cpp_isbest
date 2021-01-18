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
find_package(Qt5Network)

set(RCC_FILES resource.qrc)
#CMAKE_CURRENT_SOURCE_DIR  这是当前处理的CMakeLists.txt所在的目录
file(GLOB_RECURSE RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

qt5_add_resources(QRC_FILES ${RCC_FILES})

#引用postgresql库
#set(POSTGRESQL_DIR "C:/myinstalled/PostGresql")
#include_directories(${POSTGRESQL_DIR}/include)
#link_directories(${POSTGRESQL_DIR}/lib)

#引用mysql库
set(MYSQL_DIR "C:/work/mysql-5.7.27-winx64")
include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)


set(DIGITAL_FACTORY_PROJECT_DIR "C:/work/gitwork/cpp_isbest/DigitalFactory")

#登录模块
set(LOGIN_SOURCE_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/login_about/source)
set(LOGIN_INCLUEDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/login_about/include)
include_directories(${LOGIN_INCLUEDE_DIRECTORY})
aux_source_directory(${LOGIN_SOURCE_DIRECTORY}   LOGIN_CPPS )
file(GLOB LOGIN_HEADERS ${LOGIN_INCLUEDE_DIRECTORY}/*.h)
#file(GLOB LOGIN_CPPS ${LOGIN_SOURCE_DIRECTORY}/*.cpp) 此时与aux_source_directory重复了

#主页面窗口
set(MAINWINDOW_SOURCE_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow_about/source)
set(MAINWINDOW_INCLUEDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow_about/include)
include_directories(${MAINWINDOW_INCLUEDE_DIRECTORY})
aux_source_directory(${MAINWINDOW_SOURCE_DIRECTORY}   MAINWINDOW_CPPS )
file(GLOB MAINWINDOW_HEADERS ${MAINWINDOW_INCLUEDE_DIRECTORY}/*.h)
#file(GLOB MAINWINDOW_CPPS ${MAINWINDOW_SOURCE_DIRECTORY}/*.cpp)


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
        ${LOGIN_HEADERS}
        ${LOGIN_CPPS}

        ${MAINWINDOW_HEADERS}
        ${MAINWINDOW_CPPS}
#        loginwindow.h
#        meanshift.h
#        meanshift.cpp
        postsqlsdk.h
        postsqlsdk.cpp
#        loginwindow.ui


#        login_uis.h
#        loginform.h
#        loginform.ui
#        ${UI_DIRECTORY}
        ${QRC_FILES}
        )
endif()

target_link_libraries(DigitalFactory PRIVATE Qt5::Widgets Qt5::Sql Qt5::Network)
#target_link_libraries(DigitalFactory PRIVATE  ${POSTGRESQL_DIR}/lib/libpq.lib)
target_link_libraries(DigitalFactory PRIVATE  ${MYSQL_DIR}/lib/libmysql.lib)
