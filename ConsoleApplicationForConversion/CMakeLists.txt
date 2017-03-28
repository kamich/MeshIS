
PROJECT( ConsoleApplicationForConversion )

add_subdirectory( Tests )
include_directories( ConsoleApplicationForConversion ../Model)

set(SOURCE_FILES
	../Model/Common/CommonMeshRepresentation.h		
	../Model/IO/Export/MeshExporter.h		
	../Model/IO/Import/MeshImporter.h		
	../Model/IO/IO_Exceptions.h
	Tests/TestExporter.h 
	Tests/TestImporter.h 
	Tests/ConversionTest.h
	Converter.h )


#find_package(Boost 1.63 COMPONENTS filesystem REQUIRED)
#INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
#LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

add_executable(Application ${SOURCE_FILES} main.cpp Converter.cpp Tests/TestExporter.cpp Tests/TestImporter.cpp Tests/ConversionTest.cpp)

#TARGET_LINK_LIBRARIES( Application ${Boost_LIBRARIES} )

