cmake_minimum_required (VERSION 2.6)
project (VTK)
add_definitions(-std=c++14)
add_executable(VTK
	main.cpp
	ParaviewVTKLegacyMeshImporter.cpp
	)
