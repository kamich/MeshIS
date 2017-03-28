// Created by maria

#pragma 
#ifndef TEST_EXPORTER_H_
#define TEST_EXPORTER_H_

#include <iostream>
#include "../../Model/IO/Export/MeshExporter.h"
#include "../../Model/Common/CommonMeshRepresentation.h"
#include "../../Model/IO/IO_Exceptions.h"
using std::cout;
using std::endl;
using MeshIS::Model::Common::CMR;
using MeshIS::Model::Export::MeshExporter;
using namespace MeshIS::Model::IO;

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{

			class TestExporter : public MeshExporter
			{
			private:
				bool shouldThrowInvalidFileNameException = false;
				bool shouldThrowFileNotExistException = false;
				bool shouldThrowIncorrectFileFormatException = false;

			public:
				void Export(const string & absolute_file_path, const CMR & mesh_data) throw (FileException);

				void EnableThrowingInvalidFileNameException();
				void EnableThrowingFileNotExistException();
				void EnableThrowingIncorrectFileFormatException();

			};

		}
	}
}

#endif
