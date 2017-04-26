cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)
add_compile_options(-std=c++11)

project(MeshIS)



SET(CUSTOM_HDR
		${CMAKE_CURRENT_SOURCE_DIR}/../../../Common/CommonMeshRepresentation.h
		${CMAKE_CURRENT_SOURCE_DIR}/..//MeshExporter.h
		${CMAKE_CURRENT_SOURCE_DIR}/ParaviewVTKXMLexporter.h
		${CMAKE_CURRENT_SOURCE_DIR}/../../IO_Exceptions.h 
		${CMAKE_CURRENT_SOURCE_DIR}/../../../../TestData/CMR_objects/CMR_TestObjects.h )
include_directories(${CUSTOM_HDR})

SET(CTR_SOURCE
		${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/ParaviewVTKXMLexporter.cpp
    )

	

add_executable(App ${CTR_SOURCE} )
