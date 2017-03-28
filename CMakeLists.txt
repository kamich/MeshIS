cmake_minimum_required(VERSION 3.6)
project(ProjectCpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/Common/CommonMeshRepresentation.h
        Model/IO/Export/MeshExporter.h
        Model/IO/Import/MeshImporter.h
        Model/IO/IO_Exceptions.h Model/IO/Export/NastranExport/NastranExporter.cpp Model/IO/Export/NastranExport/NastranExporter.h Model/IO/Export/NastranExporter.cpp Model/IO/Export/NastranExporter.h)

add_executable(ProjectCpp ${SOURCE_FILES})