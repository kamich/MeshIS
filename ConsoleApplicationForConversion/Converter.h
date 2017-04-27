// Created by maria

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>
#include <memory>

#include "Tests/TestImporter.h"
#include "Tests/TestExporter.h"

using MeshIS::Model::Import::MeshImporter;
using MeshIS::Model::Export::MeshExporter;
using MeshIS::Model::Common::CMR;
using namespace std;

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{

		static const int AMOUNT_OF_ARGUMENTS = 4;

		class Converter
		{
		private:
			string importFormat, importFileName, exportFormat, exportFileName;
			unique_ptr<MeshImporter> importer;
			unique_ptr<MeshExporter> exporter;

		public:
			Converter(Tests::TestImporter &importer, Tests::TestExporter &exporter);
			Converter();
			void Convert(int amountOfArgs, char** argv);

		private:
			void SetFilesAndFormatsNamesFromCommandLineArgs(char** argv);
			bool CheckAmountOfArgs(int amountOfArgs);
			void ChooseAndSetImporer();
			void ChooseAndSetExporter();
			CMR Import();
			void Export(CMR cmr);

			string GetAbsoluteFilePath(const string& FileName);

		};

	}
}

#endif /*CONVERTER_H_*/