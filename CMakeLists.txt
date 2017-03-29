cmake_minimum_required(VERSION 3.6)
project(MeshIS_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/Common/CommonMeshRepresentation.h
        Model/IO/Export/MeshExporter.h
        Model/IO/Import/MeshImporter.h
        Model/IO/IO_Exceptions.h Model/IO/Import/ANSYS/Ansys.cpp Model/IO/Import/ANSYS/Ansys.h)

add_executable(MeshIS_master ${SOURCE_FILES})