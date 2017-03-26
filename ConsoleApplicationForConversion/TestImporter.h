// Created by maria

#pragma 
#ifndef TEST_IMPORTER_H_
#define TEST_IMPORTER_H_

#include <iostream>
#include "../Model/IO/Import/MeshImporter.h"
#include "../Model/Common/CommonMeshRepresentation.h"
#include "../Model/IO/IO_Exceptions.h"
using namespace std;

class TestImporter : public MeshIS::Model::Import::MeshImporter
{
public:
	MeshIS::Model::Common::CMR Import(const string & absolute_file_path) 
		throw ( MeshIS::Model::IO::FileException )
	{
		cout << "Import" << endl;
		return MeshIS::Model::Common::CMR();
	}
};

#endif
