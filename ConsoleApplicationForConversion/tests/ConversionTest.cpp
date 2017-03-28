// Created by maria

#include "ConversionTest.h"

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{
			
			void ConversionTest::ShouldThrowFileNotExistExceptionFromImporter()
			{
				importer.EnableThrowingFileNotExistException();
			}
			void ConversionTest::ShouldThrowInvalidFileNameExceptionFromImporter()
			{
				importer.EnableThrowingInvalidFileNameException();
			}
			void ConversionTest::ShouldThrowIncorrectFileFormatExceptionFromImporter()
			{
				importer.EnableThrowingIncorrectFileFormatException();
			}

			void ConversionTest::ShouldThrowFileNotExistExceptionFromExporter()
			{
				importer.DisableThrowingExceptions();
				exporter.EnableThrowingInvalidFileNameException();
			}
			void ConversionTest::ShouldThrowInvalidFileNameExceptionFromExporter()
			{
				importer.DisableThrowingExceptions();
				exporter.EnableThrowingInvalidFileNameException();
			}
			void ConversionTest::ShouldThrowIncorrectFileFormatExceptionFromExporter()
			{
				importer.DisableThrowingExceptions();
				exporter.EnableThrowingInvalidFileNameException();
			}

			TestImporter* ConversionTest::getImporter()
			{
				return &importer;
			}
			TestExporter* ConversionTest::getExporter()
			{
				return &exporter;
			}

		}
	}
}