// Created by maria

#pragma 
#ifndef TEST_EXPORTER_H_
#define TEST_EXPORTER_H_

#include <iostream>
#include "../Model/IO/Export/MeshExporter.h"
#include "../Model/Common/CommonMeshRepresentation.h"
#include "../Model/IO/IO_Exceptions.h"
using namespace std;

class TestExporter : public MeshIS::Model::Export::MeshExporter
{
public:
	void Export(const string & absolute_file_path, const MeshIS::Model::Common::CMR & mesh_data)
		throw (MeshIS::Model::IO::FileException)
	{
		cout << "Export" << endl;
	}
};

#endif
