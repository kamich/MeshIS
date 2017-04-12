// Created by maria

#ifndef TEST_EXPORTER_H_
#define TEST_EXPORTER_H_

#include <iostream>
#include "../../Model/IO/Export/MeshExporter.h"
#include "../../Model/IO/IO_Exceptions.h"
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
				bool shouldThrowInvalidFileNameException;
				bool shouldThrowFileNotExistException;
				bool shouldThrowIncorrectFileFormatException;

			public:
				TestExporter();
				TestExporter(TestExporter &exporter);

				void Export(const string & absolute_file_path, const CMR & mesh_data) throw (FileException);

				void EnableThrowingInvalidFileNameException();
				void EnableThrowingFileNotExistException();
				void EnableThrowingIncorrectFileFormatException();

			};

		}
	}
}

#endif
