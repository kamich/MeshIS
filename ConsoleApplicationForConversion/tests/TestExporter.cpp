// Created by maria

#include "TestExporter.h"

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{

			void TestExporter::Export(const string & absolute_file_path, const CMR & mesh_data)
				throw (FileException)
			{
				cout << "Export" << endl;
				if (shouldThrowInvalidFileNameException)
					throw InvalidFileNameException(absolute_file_path);
				if (shouldThrowFileNotExistException)
					throw FileNotExistException(absolute_file_path);
				if (shouldThrowIncorrectFileFormatException)
					throw IncorrectFileFormatException(absolute_file_path);
			}

			void TestExporter::EnableThrowingInvalidFileNameException()
			{
				shouldThrowInvalidFileNameException = true;
				shouldThrowFileNotExistException = false;
				shouldThrowIncorrectFileFormatException = false;
			}

			void TestExporter::EnableThrowingFileNotExistException()
			{
				shouldThrowFileNotExistException = true;
				shouldThrowInvalidFileNameException = false;
				shouldThrowIncorrectFileFormatException = false;
			}

			void TestExporter::EnableThrowingIncorrectFileFormatException()
			{
				shouldThrowIncorrectFileFormatException = true;
				shouldThrowInvalidFileNameException = false;
				shouldThrowFileNotExistException = false;
			}

		}
	}
}