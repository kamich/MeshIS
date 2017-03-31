cmake_minimum_required(VERSION 3.7)
project(NastranImport)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR /home/piotr/Dokumenty/boost_1_63_0)
set(Boost_LIBRARY_DIR /home/piotr/Dokumenty/boost_1_63_0/stage/lib)

set(CUSTOM_HDR
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/Common/CommonMeshRepresentation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/Import/MeshImporter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/Import/NastranMeshImporter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/FileManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/IO_Exceptions.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/IO/NastranFileType.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Model/nastran_transform.h )

set(SOURCE_FILES 
        MeshIS/Source.cpp
        MeshIS/Model/IO/Import/NastranMeshImporter.cpp
        MeshIS/Model/IO/FileManager.cpp )

find_package( Boost 1.63 COMPONENTS system filesystem REQUIRED)

include_directories(${BOOST_INCLUDE_DIT})

add_executable(NastranImport ${SOURCE_FILES})

target_link_libraries( NastranImport ${Boost_LIBRARIES})