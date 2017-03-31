cmake_minimum_required(VERSION 2.8)

project(MeshIS)

set(CMAKE_CXX_STANDARD 11)

SET(SOURCE_FILES
		Model/IO/Export/VTK_Exporter/VTK_Exporter.cpp
    )

SET(HEADER_FILES
		Model/Common/CommonMeshRepresentation.h
		Model/IO/Export/MeshExporter.h
		Model/IO/Export/VTK_Exporter/VTK_Exporter.h
		Model/IO/IO_Exceptions.h
    )

add_executable (my_executable ${SOURCE_FILES})