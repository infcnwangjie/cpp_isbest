cmake_minimum_required(VERSION 3.5)

project(DigitalFactoryServer LANGUAGES CXX)

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


find_package(Qt5 COMPONENTS Widgets Sql network REQUIRED)

set(RCC_FILES resource.qrc)
file(GLOB_RECURSE RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)#CMAKE_CURRENT_SOURCE_DIR  这是当前处理的CMakeLists.txt所在的目录
qt5_add_resources(QRC_FILES ${RCC_FILES})



set(DIGITAL_FACTORYSERVER_PROJECT_DIR "C:/work/gitwork/cpp_isbest/DigitalFactoryServer")

#后台线程
set(BEHINDSERVER_SOURCE_DIRECTORY  ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/behindListenServer/source)
set(BEHINDSERVER_INCLUEDE_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/behindListenServer/include)
include_directories(${BEHINDSERVER_INCLUEDE_DIRECTORY})
aux_source_directory(${BEHINDSERVER_SOURCE_DIRECTORY}   BEHINDSERVERCPPS ) ## 查找BEHINDSERVER_SOURCE_DIRECTORY目录下的所有源文件 ，并将名称保存到 BEHINDSERVERCPPS 变量

file(GLOB BEHINDSERVER_HEADERS ${BEHINDSERVER_INCLUEDE_DIRECTORY}/*.h)


#主页面窗口
set(MAINWINDOW_SOURCE_DIRECTORY  ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/mainWindow/source)
set(MAINWINDOW_INCLUEDE_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/mainWindow/include)
set(MAINWINDOW_UI_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/mainWindow)
include_directories(${MAINWINDOW_INCLUEDE_DIRECTORY})
aux_source_directory(${MAINWINDOW_SOURCE_DIRECTORY}   MAINWINDOW_CPPS )
file(GLOB MAINWINDOW_HEADERS ${MAINWINDOW_INCLUEDE_DIRECTORY}/*.h)



#引用mysql库
set(MYSQL_DIR "C:/work/mysql-5.7.27-winx64")
include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)



if(ANDROID)
  add_library(DigitalFactoryServer SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(DigitalFactoryServer
    main.cpp
    ${BEHINDSERVER_HEADERS}
    ${BEHINDSERVERCPPS}
    ${MAINWINDOW_HEADERS}
    ${MAINWINDOW_CPPS}
    ${MAINWINDOW_UI_DIRECTORY}/mainwindow.ui
    ${QRC_FILES}
  )
endif()


target_link_libraries(DigitalFactoryServer PRIVATE Qt5::Widgets Qt5::Sql Qt5::Network )
target_link_libraries(DigitalFactoryServer PRIVATE  ${MYSQL_DIR}/lib/libmysql.lib)
