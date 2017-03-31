cmake_minimum_required(VERSION 3.6)
project(HelloQT)

set(CMAKE_CXX_STANDARD 14)
set(CUSTOM_HDR
        ${CMAKE_CURRENT_SOURCE_DIR}/recentlyFiles.h
)
set(SOURCE_FILES main.cpp
        recentlyFiles.cpp
        )


add_executable(HelloQT ${SOURCE_FILES})