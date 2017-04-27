#tests

add_definitions( -DTESTARGS )

set(CUSTOM_HDR
	${CMAKE_CURRENT_SOURCE_DIR}/TestExporter.h 
	${CMAKE_CURRENT_SOURCE_DIR}/TestImporter.h 
	${CMAKE_CURRENT_SOURCE_DIR}/ConversionTest.h )
include_directories(${CUSTOM_HDR})

set( CTR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/TestExporter.cpp 
				${CMAKE_CURRENT_SOURCE_DIR}/TestImporter.cpp 
				${CMAKE_CURRENT_SOURCE_DIR}/ConversionTest.cpp
				${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp 
				${CMAKE_CURRENT_SOURCE_DIR}/../Converter.cpp)

add_executable(Tests ${CTR_SOURCE} )