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
				exporter.EnableThrowingFileNotExistException();
			}
			void ConversionTest::ShouldThrowInvalidFileNameExceptionFromExporter()
			{
				importer.DisableThrowingExceptions();
				exporter.EnableThrowingInvalidFileNameException();
			}
			void ConversionTest::ShouldThrowIncorrectFileFormatExceptionFromExporter()
			{
				importer.DisableThrowingExceptions();
				exporter.EnableThrowingIncorrectFileFormatException();
			}

			Tests::TestImporter ConversionTest::getImporter()
			{
				return (importer);
			}
			Tests::TestExporter ConversionTest::getExporter()
			{
				return (exporter);
			}
		}
	}
}