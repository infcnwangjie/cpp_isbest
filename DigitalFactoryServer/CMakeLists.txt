cmake_minimum_required(VERSION 3.5)

project(DigitalFactoryServer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#SET(QT_USE_QTNETWORK true)

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


find_package(Qt5 COMPONENTS Widgets Sql   REQUIRED) #QtNetwork
find_package(Qt5Network)

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


#service
set(SERVICE_SOURCE_DIRECTORY  ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/service/source)
set(SERVICE_INCLUEDE_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/service/include)
#set(SERVICE_UI_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/service)
include_directories(${SERVICE_INCLUEDE_DIRECTORY})
aux_source_directory(${SERVICE_SOURCE_DIRECTORY}   SERVICE_CPPS )
file(GLOB SERVICE_HEADERS ${SERVICE_INCLUEDE_DIRECTORY}/*.h)


#dao
set(DAO_SOURCE_DIRECTORY  ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/dao/source)
set(DAO_INCLUEDE_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/dao/include)
#set(SERVICE_UI_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/service)
include_directories(${DAO_INCLUEDE_DIRECTORY})
aux_source_directory(${DAO_SOURCE_DIRECTORY}   DAO_CPPS )
file(GLOB DAO_HEADERS ${DAO_INCLUEDE_DIRECTORY}/*.h)



#common
set(COMMON_SOURCE_DIRECTORY  ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/common/source)
set(COMMON_INCLUEDE_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/common/include)
#set(SERVICE_UI_DIRECTORY ${DIGITAL_FACTORYSERVER_PROJECT_DIR}/service)
include_directories(${COMMON_INCLUEDE_DIRECTORY})
aux_source_directory(${COMMON_SOURCE_DIRECTORY}   COMMON_CPPS )
file(GLOB COMMON_HEADERS ${COMMON_INCLUEDE_DIRECTORY}/*.h ${COMMON_INCLUEDE_DIRECTORY}/*.hpp)



#引用mysql库
set(MYSQL_DIR "C:/work/mysql-5.7.27-winx64")
include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)




if(ANDROID)
  add_library(DigitalFactoryServer SHARED
      mainwindow.cpp
      mainwindow.h
    main.cpp
    mainwindow.ui
  )
else()
  add_executable(DigitalFactoryServer
    main.cpp
    ${BEHINDSERVER_HEADERS}
    ${BEHINDSERVERCPPS}
    ${COMMON_HEADERS}
    ${COMMON_CPPS}
    ${MAINWINDOW_HEADERS}
    ${MAINWINDOW_CPPS}
    ${MAINWINDOW_UI_DIRECTORY}/mainwindow.ui
    ${SERVICE_HEADERS}
    ${SERVICE_CPPS}
    ${DAO_HEADERS}
    ${DAO_CPPS}
    ${QRC_FILES}
  )
endif()

#message(${QT_QTNETWORK_LIBRARY})

target_link_libraries(DigitalFactoryServer PRIVATE Qt5::Widgets Qt5::Sql Qt5::Network  ) #${QT_QTNETWORK_LIBRARY}
target_link_libraries(DigitalFactoryServer PRIVATE  ${MYSQL_DIR}/lib/libmysql.lib)
