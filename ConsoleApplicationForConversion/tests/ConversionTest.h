// Created by maria

#pragma 
#ifndef CONVERTERSION_TEST_H_
#define CONVERTERSION_TEST_H_

#include <string>
#include <memory>
#include "TestExporter.h"
#include "TestImporter.h"

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		namespace Tests
		{

			class ConversionTest
			{
			private:
				TestImporter importer;
				TestExporter exporter;
				
			public:
				void ShouldThrowInvalidFileNameExceptionFromImporter();
				void ShouldThrowFileNotExistExceptionFromImporter();
				void ShouldThrowIncorrectFileFormatExceptionFromImporter();

				void ShouldThrowInvalidFileNameExceptionFromExporter();
				void ShouldThrowFileNotExistExceptionFromExporter();
				void ShouldThrowIncorrectFileFormatExceptionFromExporter();

				Tests::TestImporter getImporter();
				Tests::TestExporter getExporter();
			};

		}
	}
}

#endif /*CONVERTERSION_TEST_H_*/