﻿// Created by maria

#include <iostream>
#include "Converter.h"
#include "Tests/ConversionTest.h"

using MeshIS::ConsoleApplicationForConversion::Converter;
using MeshIS::ConsoleApplicationForConversion::Tests::ConversionTest;

/*
Available formats
Abacus	 		inp
Ansys			msh
GMsh			geo
ModFEM			dat
Nastran
free		bdf
long		bdf
short		bdf
ParaviewVTK		vtk
Su2				su2
UniversalUNV	unv
*/

int main(int argc, char** argv)
{
#ifdef TESTARGS
	cout << "Test args" << endl;
	//	for (int i = 1; i < argc; i++)	cout << argv[i] << endl;
#endif

	/*
	ConversionTest test;

	//		test.ShouldThrowFileNotExistExceptionFromImporter();
	//		test.ShouldThrowInvalidFileNameExceptionFromImporter();
	//		test.ShouldThrowIncorrectFileFormatExceptionFromImporter();

	//		test.ShouldThrowFileNotExistExceptionFromExporter();
	//		test.ShouldThrowInvalidFileNameExceptionFromExporter();
	//		test.ShouldThrowIncorrectFileFormatExceptionFromExporter();

	Converter converter(test.getImporter(), test.getExporter());
	*/

	Converter converter;
	converter.Convert(argc, argv);
	
	return 0;
}