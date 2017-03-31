cmake_minimum_required(VERSION 3.6)
project(MeshIS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/Common/CommonMeshRepresentation.h
        Model/IO/Export/MeshExporter.h
        Model/IO/Import/MeshImporter.h
        Model/IO/IO_Exceptions.h "Model/Mesh Statistics/MeshStatistics.cpp" "Model/Mesh Statistics/MeshStatistics.h")

add_executable(MeshIS ${SOURCE_FILES} "Model/test.cpp")
