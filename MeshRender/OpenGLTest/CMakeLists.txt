cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

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
SET (this_target OpenGLTest)
PROJECT(${this_target})

#find_package(PkgConfig REQUIRED)
#pkg_search_module(GLFW REQUIRED glfw3)
find_package(glfw3 3.2 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS})
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
endif()

## section: include directory
INCLUDE_DIRECTORIES(
../packages/GLMathematics.0.9.5.4/build/native/include
../../Model/Common
  )

## section: source files
# Add your source files here (one file per line), please SORT in alphabetical order for future maintenance
SET (${this_target}_SOURCE_FILES
    controls.cpp
	main.cpp
	shader.cpp
	texture.cpp
	VertexLoader.cpp
    )

## section: header files
# Add your header files here(one file per line), please SORT in alphabetical order for future maintenance!
SET(${this_target}_HEADER_FILES
    controls.hpp
	shader.hpp
	texture.hpp
	VertexLoader.h
    )

SOURCE_GROUP("Resource Files" FILES 
	
	)
SOURCE_GROUP("Header Files" FILES 
	
	)
SOURCE_GROUP("Source Files" FILES 
	main.cpp
	VertexLoader.cpp
	controls.cpp
	shader.cpp
	texture.cpp
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
-lGL
    )

## section: add target

ADD_EXECUTABLE(${this_target} ${${this_target}_SOURCE_FILES})

target_link_libraries(${this_target} ${GLFW_LIBRARIES} ${OPENGL_LIBRARY} ${GLEW_LIBRARIES})
