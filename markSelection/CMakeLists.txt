cmake_minimum_required(VERSION 3.6)
project(markSelection)

set(CMAKE_CXX_STANDARD 14)
set(CUSTOM_HDR
        ${CMAKE_CURRENT_SOURCE_DIR}/markselection.h
)
set(SOURCE_FILES main.cpp
        markselection.cpp
        )


add_executable(markSelection ${SOURCE_FILES})