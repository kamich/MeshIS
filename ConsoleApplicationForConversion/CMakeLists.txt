
PROJECT( ConsoleApplicationForConversion )

add_subdirectory( tests )
include_directories( ConsoleApplicationForConversion ../Model)

set(SOURCE_FILES
	../Model/Common/CommonMeshRepresentation.h		
	../Model/IO/Export/MeshExporter.h		
	../Model/IO/Import/MeshImporter.h		
	../Model/IO/IO_Exceptions.h)		

add_executable(Application ${SOURCE_FILES} main.cpp)