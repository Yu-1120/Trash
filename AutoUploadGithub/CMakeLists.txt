cmake_minimum_required(VERSION 3.5)

project(AutoUploadGithub LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")#这个是你安装Qt的路径，让他找到
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

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (ANDROID)
    add_library(AutoUploadGithub SHARED
            main.cpp
            myprocess.cpp
            myprocess.h
            myprocess.ui
            )
else ()
    add_executable(AutoUploadGithub
            main.cpp
            myprocess.cpp
            myprocess.h
            myprocess.ui

            )
endif ()

target_link_libraries(AutoUploadGithub PRIVATE Qt5::Widgets )
target_include_directories(AutoUploadGithub PRIVATE "${CMAKE_BINARY_DIR}/Test_autogen/i")
