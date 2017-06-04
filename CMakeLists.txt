
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LINKER_FLAGS "-lglut, 'lGL")
# Project Name
PROJECT(MeshIS)

IF(WIN32)
    set(GLUT_INCLUDE_DIR "C:/Opengl/freeglut/include")
    set(GLUT_glut_LIBRARY "C:/Opengl/freeglut/lib/")
    set(GLEW_INCLUDE_DIR "C:/Opengl/glew-1.11.0/include")
    set(GLEW_LIBRARY "C:/Opengl/Glew and Glut/glew-1.11.0/lib")
    include_directories("C:/Opengl/freeglut/include" "C:/Opengl/glew-1.11.0/include")
    link_directories("C:/Opengl/freeglut/lib/" "C:/Opengl/Glew and Glut/glew-1.11.0/lib")
ENDIF()

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif(NOT GLEW_FOUND)

set(Sources
        View/StatisticsDisplayer.h
        View/ViewInitializer.h
        View/AppStartPoint.h
        View/AppStartPoint.cpp
        View/StatisticsDisplayer.cpp
        View/ViewInitializer.cpp
        Model/Common/CommonMeshRepresentation.h
        Model/Mesh_Statistics/MeshStatistics.cpp
        Model/Mesh_Statistics/MeshStatistics.h
        Model/IO/State/StateManager.h
        Model/IO/State/StateManager.cpp
        View/main.cpp
        )
add_executable(Mesh ${Sources})

target_link_libraries(Mesh ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

