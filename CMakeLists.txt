cmake_minimum_required(VERSION 3.6)
project(cpp1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/Common/CommonMeshRepresentation.h
        Model/IO/Export/MeshExporter.h
        Model/IO/Import/MeshImporter.h
        Model/IO/IO_Exceptions.h Model/IO/ExportNastran/NastranExporter.cpp Model/IO/ExportNastran/NastranExporter.h)

add_executable(cpp1 ${SOURCE_FILES} Model/IO/ExportNastran/NastranExporter.cpp)
