cmake_minimum_required(VERSION 3.6)
project(ExportMsh)

set(CMAKE_CXX_STANDARD 14)
set(CUSTOM_HDR
        ${CMAKE_CURRENT_SOURCE_DIR}/ExportGMsh.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Model/Common/CommonMeshRepresentation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../MeshExporter)
set(SOURCE_FILES main.cpp
        ExportGmsh.cpp

        )


add_executable(ExportMsh ${SOURCE_FILES})