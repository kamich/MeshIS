#tests

add_definitions( -DTESTARGS )

set(CUSTOM_HDR
	${CMAKE_CURRENT_SOURCE_DIR}/InversionTest.h
	${CMAKE_CURRENT_SOURCE_DIR}/CMRDataPrinter.h )
include_directories(${CUSTOM_HDR})

set( CTR_SOURCE 
				${CMAKE_CURRENT_SOURCE_DIR}/InversionTest.cpp
				${CMAKE_CURRENT_SOURCE_DIR}/CMRDataPrinter.cpp
				${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp 
				${CMAKE_CURRENT_SOURCE_DIR}/../Inverter.cpp)

add_executable(Tests ${CTR_SOURCE} )