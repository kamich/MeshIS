cmake_minimum_required(VERSION 3.6)
project(AbaqusExporter)

set(CMAKE_CXX_STANDARD 14)
set(CUSTOM_HDR
        ${CMAKE_CURRENT_SOURCE_DIR}/ModFemExporter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/helperMethods.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/Common/CommonMeshRepresentation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/helperMethods.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/Export/MeshExporter)
set(SOURCE_FILES main.cpp
        ModFemExporter.cpp

        )


add_executable(AbaqusExporter ${SOURCE_FILES})