// Created by maria

#include "TestImporter.h"

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{
			TestImporter::TestImporter()
			{
				shouldThrowInvalidFileNameException = false;
				shouldThrowFileNotExistException = false;
				shouldThrowIncorrectFileFormatException = false;
			}

			TestImporter::TestImporter(TestImporter &imporetr)
			{
				this->shouldThrowFileNotExistException = imporetr.shouldThrowFileNotExistException;
				this->shouldThrowInvalidFileNameException = imporetr.shouldThrowInvalidFileNameException;
				this->shouldThrowIncorrectFileFormatException = imporetr.shouldThrowIncorrectFileFormatException;
			}

			CMR TestImporter::Import(const string & absolute_file_path)
				throw (FileException)
			{
				cout << "Start Import..." << endl;
				if (shouldThrowInvalidFileNameException)
					throw InvalidFileNameException(absolute_file_path);
				if (shouldThrowFileNotExistException)
					throw FileNotExistException(absolute_file_path);
				if (shouldThrowIncorrectFileFormatException)
					throw IncorrectFileFormatException(absolute_file_path);
				cout << "...Import Finished." << endl;
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