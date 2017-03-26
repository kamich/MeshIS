// Created by maria

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

#include "../Model/Common/CommonMeshRepresentation.h"
#include "../Model/IO/Export/MeshExporter.h"
#include "../Model/IO/Import/MeshImporter.h"
#include "../Model/IO/IO_Exceptions.h"

#include "TestImporter.h"
#include "TestExporter.h"

using namespace std;
static const int AMOUNT_OF_ARGUMENTS = 4;

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

	if (argc != (AMOUNT_OF_ARGUMENTS + 1))
	{
		cerr << "The number of entered arguments (" << argc-1 << ") is invalid." << endl;
		cerr << "The correct number of arguments is four:" << endl; 
		cerr << "file_type_to_import file_name_to_import file_type_to_expotr file_name_to_export" << endl;
		system("pause");
		exit(1);
	}

	string importFormat(argv[1]);
	string nameOfFileToImport(argv[2]);
	string exportFormat(argv[3]);
	string nameOfFileToExport(argv[4]);

	MeshIS::Model::Import::MeshImporter *importer;
	MeshIS::Model::Export::MeshExporter *exporter;

	if (importFormat == "TestFormat")
		importer = new TestImporter();
	else 
	{
		cerr << "The selected format to import (" << importFormat << ") is not supported." << endl;
		system("pause");
		exit(1);
	}

	if (exportFormat == "TestFormat")
		exporter = new TestExporter();
	else 
	{
		cerr << "The selected format to export (" << exportFormat << ") is not supported." << endl;
		system("pause");
		exit(1);
	}

	MeshIS::Model::Common::CommonMeshRepresentation meshData;
	try 
	{
		meshData = importer->Import(nameOfFileToImport);
		exporter->Export(nameOfFileToExport, meshData);
	}
	catch (MeshIS::Model::IO::InvalidFileNameException invalidFileName) 
	{
		cerr << "An error occured: INVALID FILE NAME." << endl;
		cerr << "The entered file name (" << invalidFileName.get_problematic_filename() << ") is incorrect." << endl;
		exit(1);
	}
	catch (MeshIS::Model::IO::FileNotExistException fileNotExist) 
	{
		cerr << "An error occured: FILE NOT EXIST." << endl;
		cerr << "The file with the given name (" << fileNotExist.get_problematic_filename() << ") does not exist." << endl;
		exit(1);
	}
	catch (MeshIS::Model::IO::IncorrectFileFormatException incorrectFileFormat) 
	{
		cerr << "An error occured: INCORRECT FILE FORMAT." << endl;
		cerr << "The format of the data in the file (" << incorrectFileFormat.get_problematic_filename() << ") does not match the selected format for conversion." << endl;
		exit(1);
	}
	catch (...) 
	{
		cerr << "An error occured." << endl;
		exit(1);
	}

	system("pause");
	return 0;
}