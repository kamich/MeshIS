cmake_minimum_required(VERSION 3.6)
project(AbaqusExporter)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        AbaqusExporter.cpp
        AbaqusExporter.h
        )
add_executable(AbaqusExporter ${SOURCE_FILES})