// Created by maria

#ifndef TEST_IMPORTER_H_
#define TEST_IMPORTER_H_

#include <iostream>
#include "../../Model/IO/Import/MeshImporter.h"
#include "../../Model/IO/IO_Exceptions.h"
using MeshIS::Model::Common::CMR;
using MeshIS::Model::Import::MeshImporter;
using namespace MeshIS::Model::IO;

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{

			class TestImporter : public MeshImporter
			{
			private:
				bool shouldThrowInvalidFileNameException;
				bool shouldThrowFileNotExistException;
				bool shouldThrowIncorrectFileFormatException;

			public:
				TestImporter();
				TestImporter(TestImporter &imporetr);

				CMR Import(const string & absolute_file_path) throw (FileException);

				void EnableThrowingInvalidFileNameException();
				void EnableThrowingFileNotExistException();
				void EnableThrowingIncorrectFileFormatException();
				void DisableThrowingExceptions();

			};

		}
	}
}

#endif
