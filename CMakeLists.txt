cmake_minimum_required(VERSION 2.8)

## section: Macro
MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
  IF(MSVC)
    GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
    SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
    SET(Sources ${${SourcesVar}})

    SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
                                PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_OUTPUTS "${PrecompiledBinary}")
    SET_SOURCE_FILES_PROPERTIES(${Sources}
                                PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledBinary}\" /FI\"${PrecompiledBinary}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_DEPENDS "${PrecompiledBinary}")  
    # Add precompiled header to SourcesVar
    LIST(APPEND ${SourcesVar} ${PrecompiledSource})
  ENDIF(MSVC)
ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

## start setting
SET (this_target Project4)
PROJECT(${this_target})



## section: include directory
INCLUDE_DIRECTORIES(
  
  )

## section: source files
# Add your source files here (one file per line), please SORT in alphabetical order for future maintenance
SET (${this_target}_SOURCE_FILES
    MeshIS/Model/IO/Export/Nastran/BulkData/BulkData.cpp
	MeshIS/Model/Common/CommonMeshRepresentation.cpp
	MeshIS/Model/IO/Export/Nastran/main.cpp
	MeshIS/Model/IO/Export/MeshExporter.cpp
	MeshIS/Model/IO/Export/Nastran/NastranExporter/NastranExporter.cpp
	MeshIS/Model/IO/Export/Nastran/BulkData/BulkData.cppShortBulkData.cpp
    )

## section: header files
# Add your header files here(one file per line), please SORT in alphabetical order for future maintenance!
SET(${this_target}_HEADER_FILES
    MeshIS/Model/IO/Export/Nastran/BulkData/BulkData.cppBulkData.h
	MeshIS/Model/Common/CommonMeshRepresentation.h
	MeshIS/Model/IO/Export/MeshExporter.h
	MeshIS/Model/IO/Export/Nastran/NastranExporter/NastranExporter.h
	MeshIS/Model/IO/Export/Nastran/BulkData/BulkData.cppShortBulkData.h
    )

SOURCE_GROUP("Source Files" FILES 
	
	)
SOURCE_GROUP("Resource Files" FILES 
	
	)
SOURCE_GROUP("Header Files" FILES 
	
	)


## section: precompiled header	
#ADD_MSVC_PRECOMPILED_HEADER("precompiled.h" "precompiled.cpp" MySources)
#ADD_LIBRARY(MyLibrary ${MySources})

SET_SOURCE_FILES_PROPERTIES(${this_target}_HEADER_FILES
                            PROPERTIES HEADER_FILE_ONLY TRUE)
LIST(APPEND ${this_target}_SOURCE_FILES ${${this_target}_HEADER_FILES})

## section: add definitions
#   add prefix -D. example> -DSHP
#  - DO NOT add  the following definitions(already defined in ${OSP_DEFINITIONS}:
#   -DSHP, -DWIN32, -D_WINDOWS, -D_DEBUG, -D_USRDLL, -D_CRT_SECURE_NO_DEPRECATE
ADD_DEFINITIONS(
    
    )

## section: add target


