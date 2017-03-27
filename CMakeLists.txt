cmake_minimum_required(VERSION 3.6)
project(MeshIS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/Common/CommonMeshRepresentation.h
        Model/IO/Export/MeshExporter.h
        Model/IO/Import/MeshImporter.h
        Model/IO/IO_Exceptions.h
        TestData/MeshFiles/Abaqus/test1_fluent.inp
        TestData/MeshFiles/Ansys/test1.msh
        TestData/MeshFiles/GMsh/example1.geo
        TestData/MeshFiles/GMsh/example1.msh
        TestData/MeshFiles/ModFEM/2_prism_mesh.dat
        TestData/MeshFiles/ModFEM/single_tetra.dat
        TestData/MeshFiles/Nastran/FREE/example1_free.bdf
        TestData/MeshFiles/Nastran/LONG/example1_long.bdf
        TestData/MeshFiles/Nastran/LONG/test1_fluent.bdf
        TestData/MeshFiles/Nastran/SHORT/example1_small.bdf
        TestData/MeshFiles/Nastran/SHORT/mesh.nas
        TestData/MeshFiles/Nastran/SHORT/mesh_1.nas
        "TestData/MeshFiles/Paraview VTK/legacy/example1_ascii.vtk"
        TestData/MeshFiles/Su2/example1.su2
        "TestData/MeshFiles/Universal UNV/example1.unv"
        TestData/MeshFiles/test1.png
        .gitignore
        LICENSE
        README.md Model/IO/Import/Abaqus/Abaqus_Import.h Model/IO/Import/Abaqus/Abaqus_Import.cpp)

add_executable(MeshIS ${SOURCE_FILES} Model/IO/Import/Abaqus/Abaqus_Import.h Model/IO/Import/Abaqus/Abaqus_Import.cpp)