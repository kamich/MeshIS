cmake_minimum_required(VERSION 2.8)

project(MeshIS)

set(CMAKE_CXX_STANDARD 11)

SET(SOURCE_FILES
		Model/IO/Import/VTU_xml/vtu_xml_importer.cpp
    )

SET(HEADER_FILES
		Model/Common/CommonMeshRepresentation.h
		Model/IO/Export/MeshExporter.h
		Model/IO/Import/MeshImporter.h
		Model/IO/Import/VTU_xml/rapidXML/rapidxml.hpp
		Model/IO/Import/VTU_xml/vtu_xml_importer.h
		Model/IO/IO_Exceptions.h
    )

add_executable(MeshIS ${SOURCE_FILES} main.cpp)