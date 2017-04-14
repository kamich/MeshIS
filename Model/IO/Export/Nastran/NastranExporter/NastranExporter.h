//*************************
//Created by Dominik Kopaczka
//*************************

#ifndef CPP_NASTRANEXPORTER_H
#define CPP_NASTRANEXPORTER_H

#include "../../MeshExporter.h"
#include"../BulkData/BulkData.h"
#include <iostream>
#include <fstream>
#include <memory>

using namespace MeshIS::Model::Export::Nastran::BData;
using namespace MeshIS::Model::Export;
using namespace MeshIS::Model::Common;

using std::string;

namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{
			namespace Nastran
			{
				struct File;

				class NastranExporter : public MeshExporter {
				
				//All State Of Nastran Version/////////////////////////////////
				public:     enum class Type_Of_Nastran_Version {
					FREE,
					SHORT,
					LONG
				};
				///////////////////////////////////////////////////////////////

				//Private Members//////////////////////////////////////////////
				private:	std::unique_ptr<File> ptr_file_members;
				///////////////////////////////////////////////////////////////

				//Constructors/////////////////////////////////////////////////
				public:     NastranExporter();
				public:     NastranExporter(Type_Of_Nastran_Version type_of_nastran);
				///////////////////////////////////////////////////////////////

				//Virtual Method From MeshExporter/////////////////////////////
				public:		void virtual Export(const string& absolute_file_path, const CMR& mesh_data) final;
				///////////////////////////////////////////////////////////////
				
				//Set State Of Nastran Version Functions///////////////////////
				private:	void set_default_state() noexcept;
				public:		void set_state_of_nastran_version(Type_Of_Nastran_Version type) noexcept;
				///////////////////////////////////////////////////////////////
				};

				struct File {
					std::ofstream os;
					NastranExporter::Type_Of_Nastran_Version state_of_nastran_version;

					//At the beginning this was unique_ptr<BulkData>, but after writing 
					//"set_block_of_bulk_data" I had to change to common pointer
					BulkData* bulkData;
				};
			}
		}
	}
}
#endif //CPP_NASTRANEXPORTER_H