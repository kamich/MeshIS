cmake_minimum_required(VERSION 2.8)

PROJECT( ConsoleApplicationForConversion )
add_subdirectory( Tests )

set( BOOST_ROOT "C:/Boost")
set( Boost_INCLUDE_DIR "C:/Boost/include/boost-1_63")
set( Boost_LIBRARY_DIR "C:/Boost/lib")
find_package(Boost 1.63 COMPONENTS system filesystem REQUIRED)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")

 
set(CUSTOM_HDR
	${CMAKE_CURRENT_SOURCE_DIR}/../Model/Common/CommonMeshRepresentation.h		
	${CMAKE_CURRENT_SOURCE_DIR}/../Model/IO/Export/MeshExporter.h		
	${CMAKE_CURRENT_SOURCE_DIR}/../Model/IO/Import/MeshImporter.h		
	${CMAKE_CURRENT_SOURCE_DIR}/../Model/IO/IO_Exceptions.h
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/TestExporter.h 
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/TestImporter.h 
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/ConversionTest.h
	${CMAKE_CURRENT_SOURCE_DIR}/Converter.h )
include_directories(${CUSTOM_HDR})

set( CTR_SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Converter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/TestExporter.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/TestImporter.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/Tests/ConversionTest.cpp)
add_executable(Application ${CTR_SOURCE} )
 
target_link_libraries( Application ${Boost_LIBRARIES} )