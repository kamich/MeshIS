cmake_minimum_required(VERSION 3.6)

PROJECT( InvertSelection )
add_subdirectory( Tests )


set(CUSTOM_HDR
	${CMAKE_CURRENT_SOURCE_DIR}/../Model/Common/CommonMeshRepresentation.h			
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/InversionTest.h
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/CMRDataPrinter.h
	${CMAKE_CURRENT_SOURCE_DIR}/Inverter.h )
include_directories(${CUSTOM_HDR})

set( CTR_SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Inverter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/InversionTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/CMRDataPrinter.cpp)
add_executable(Application ${CTR_SOURCE} )
 
target_link_libraries( Application ${Boost_LIBRARIES} )