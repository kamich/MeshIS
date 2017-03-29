// Created by maria

#include "Converter.h"
//#include <boost/filesystem.hpp>

using std::cerr;

namespace MeshIS
{
	namespace ConsoleApplicationForConversion
	{
		Converter::Converter()
		{
			importer = nullptr;
			exporter = nullptr;
		}
		Converter::Converter(Tests::TestImporter* importer, Tests::TestExporter* exporter)
		{
			this->importer = importer;
			this->exporter = exporter;
		}

		void Converter::Convert(int argc, char** argv)
		{
			if (!CheckAmountOfArgs(argc))
			{
				cerr << "The number of entered arguments (" << argc - 1 << ") is invalid." << endl;
				cerr << "The correct number of arguments is four:" << endl;
				cerr << "file_type_to_import file_name_to_import file_type_to_expotr file_name_to_export" << endl;
				system("pause");
				exit(1);
			}
			SetFilesAndFormatsNamesFromCommandLineArgs(argv);

			if (importer == nullptr || exporter == nullptr)
			{
				ChooseAndSetImporer();
				ChooseAndSetExporter();
			}

			try
			{
				CMR cmr = Import();
				Export(cmr);
			}
			catch (MeshIS::Model::IO::InvalidFileNameException& invalidFileName)
			{
				cerr << "An error occured: INVALID FILE NAME." << endl;
				cerr << "The entered file name (" << invalidFileName.get_problematic_filename() << ") is incorrect." << endl;
				system("pause");
				exit(1);
			}
			catch (MeshIS::Model::IO::FileNotExistException& fileNotExist)
			{
				cerr << "An error occured: FILE NOT EXIST." << endl;
				cerr << "The file with the given name (" << fileNotExist.get_problematic_filename() << ") does not exist." << endl;
				system("pause");
				exit(1);
			}
			catch (MeshIS::Model::IO::IncorrectFileFormatException& incorrectFileFormat)
			{
				cerr << "An error occured: INCORRECT FILE FORMAT." << endl;
				cerr << "The format of the data in the file (" << incorrectFileFormat.get_problematic_filename() << ") does not match the selected format for conversion." << endl;
				system("pause");
				exit(1);
			}
			catch (...)
			{
				cerr << "An error occured." << endl;
				system("pause");
				exit(1);
			}
		}

		bool Converter::CheckAmountOfArgs(int amountOfArgs)
		{
			if (amountOfArgs != AMOUNT_OF_ARGUMENTS + 1)
				return false;
			return true;
		}
		void Converter::SetFilesAndFormatsNamesFromCommandLineArgs(char **argv)
		{
			importFormat = argv[1];
			importFileName = argv[2];
			exportFormat = argv[3];
			exportFileName = argv[4];
		}
		void Converter::ChooseAndSetImporer()
		{
			if (importFormat == "TestFormat")
				importer = new Tests::TestImporter();
			else
			{
				cerr << "The selected format to import (" << importFormat << ") is not supported." << endl;
				system("pause");
				exit(1);
			}
		}
		void Converter::ChooseAndSetExporter()
		{
			if (exportFormat == "TestFormat")
				exporter = new Tests::TestExporter();
			else
			{
				cerr << "The selected format to export (" << exportFormat << ") is not supported." << endl;
				system("pause");
				exit(1);
			}
		}
		CMR Converter::Import()
		{
			return importer->Import(GetAbsoluteFilePath(importFileName));
		}
		void Converter::Export(CMR cmr)
		{
			exporter->Export(GetAbsoluteFilePath(exportFileName), cmr);
		}

		string Converter::GetAbsoluteFilePath(const string& fileName)
		{
/*
			boost::filesystem::path path(fileName);
			boost::filesystem::path absolutePath = boost::filesystem::complete(path);
			return absolutePath.string();
*/
			return fileName;
		}

	}
}