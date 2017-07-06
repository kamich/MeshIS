cmake_minimum_required(VERSION 3.7)
project(PredefiniowaneWidoki)

set(CMAKE_CXX_STANDARD 14)

set(Glew_INCLUDE_DIR /home/Michal/Documents/Visual Studio 2015/Projects/glut/glew-1.11.0)
set(Freeglut_INCLUDE_DIR /home/Michal/Documents/Visual Studio 2015/Projects/glut/freeglut)
set(Glew_LIBRARY_DIR /home/Michal/Documents/Visual Studio 2015/Projects/glut/glew-1.11.0/lib)
set(Freeglut_LIBRARY_DIR /home/Michal/Documents/Visual Studio 2015/Projects/glut/freeglut/lib)

set(CUSTOM_HDR
        
		 )

set(SOURCE_FILES 
        PredefiniowaneWidoki.cpp
         )

find_package( Glew 1.11.0 COMPONENTS system filesystem REQUIRED)

include_directories(${GLEW_INCLUDE_DIT}
					${FREEGLUT_INCLUDE_DIT})

add_executable(PredefiniowaneWidoki ${SOURCE_FILES})

target_link_libraries( PredefiniowaneWidoki ${Glew_LIBRARIES}
											${Freeglut_LIBRARIES})