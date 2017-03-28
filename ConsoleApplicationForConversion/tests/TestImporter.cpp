// Created by maria

#include "TestImporter.h"

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{
			CMR TestImporter::Import(const string & absolute_file_path)
				throw (FileException)
			{
				cout << "Import" << endl;
				if (shouldThrowInvalidFileNameException)
					throw InvalidFileNameException(absolute_file_path);
				if (shouldThrowFileNotExistException)
					throw FileNotExistException(absolute_file_path);
				if (shouldThrowIncorrectFileFormatException)
					throw IncorrectFileFormatException(absolute_file_path);
				return CMR();
			}

			void TestImporter::EnableThrowingInvalidFileNameException()
			{
				shouldThrowInvalidFileNameException = true;
				shouldThrowFileNotExistException = false;
				shouldThrowIncorrectFileFormatException = false;
			}

			void TestImporter::EnableThrowingFileNotExistException()
			{
				shouldThrowFileNotExistException = true;
				shouldThrowInvalidFileNameException = false;
				shouldThrowIncorrectFileFormatException = false;
			}

			void TestImporter::EnableThrowingIncorrectFileFormatException()
			{
				shouldThrowIncorrectFileFormatException = true;
				shouldThrowInvalidFileNameException = false;
				shouldThrowFileNotExistException = false;
			}

			void TestImporter::DisableThrowingExceptions()
			{
				shouldThrowIncorrectFileFormatException = false;
				shouldThrowInvalidFileNameException = false;
				shouldThrowFileNotExistException = false;
			}

		}
	}
}