cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES Model/IO/Import/VTU_Import/Test/test.cpp
        Model/IO/Import/VTU_Import/VTU_import.cpp
        Model/IO/Import/VTU_Import/VTU_import.h
)

add_executable(untitled ${SOURCE_FILES})