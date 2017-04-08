//*************************
//Created by Dominik Kopaczka
//*************************

#ifndef CPP_NASTRANEXPORTER_H
#define CPP_NASTRANEXPORTER_H

#include "../../MeshExporter.h"
#include "../BulkData/ShortBulkData.h"
#include"../BulkData/FreeBulkData.h"
#include"../BulkData/LongBulkData.h"
#include<iostream>
#include<fstream>
#include <iterator>
#include<vector>
#include<boost/filesystem/path.hpp>

using std::string;
using namespace MeshIS::Model::Export::Nastran::BData;
using namespace MeshIS::Model::Export;
using namespace MeshIS::Model::Common;
namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{
			namespace Nastran
			{
				/*
					The most important class on my branch. 
					Uses a polymorphic pointer to BulkData.
					Depending on the version, you just need 
					to change "state_of_nastran_version" variable, and
					call "Export" function.
				*/
				class NastranExporter : public MeshExporter {
				
				//All State Of Nastran Version/////////////////////////////////
				public:     enum class Type_Of_Nastran_Version {
					FREE,
					SHORT,
					LONG
				};
				///////////////////////////////////////////////////////////////

				//Private Members//////////////////////////////////////////////
				private:	std::ofstream os;
				private:    Type_Of_Nastran_Version state_of_nastran_version;
				//At the beginning this was unique_ptr<BulkData>, but after writing 
				//"set_block_of_bulk_data" I had to change to common pointer
				private:	BulkData* bulkData;
				///////////////////////////////////////////////////////////////

				//Constructors/////////////////////////////////////////////////
				public:     NastranExporter();
				public:     NastranExporter(Type_Of_Nastran_Version type_of_nastran);
				///////////////////////////////////////////////////////////////

				//Destructor///////////////////////////////////////////////////
				public:		~NastranExporter();
				///////////////////////////////////////////////////////////////

				//Virtual Method From MeshExporter////////////////////////////
				public:		void virtual Export(const string& absolute_file_path, const CMR& mesh_data) final;
				///////////////////////////////////////////////////////////////
				
				//Methods Create A Nastran File Depending On Nastran Version/// 
				private:    void set_bulkdata_pointer_depending_on_the_nastran_version_state() noexcept;
				private:    void create_nastran_file_from_CMR(const string & absolute_file_path, const CMR & mesh_data) noexcept;

				private:	void create_bulk_data(const CMR & mesh_data) noexcept;
				private:	void set_GRID(const CMR & mesh_data) noexcept;
				private:	void set_CTETRA(const CMR & mesh_data) noexcept;
				private:	void set_CPENTA(const CMR & mesh_data) noexcept;

				private: void set_header(string & string);

				//Because set_GRID, set_CTETRA, set_CPENTA do similar things i decided to use inline tamplate function
				template< class type_of_mesh_part>
				inline void set_block_of_bulk_data(
					std::vector<type_of_mesh_part> const& mesh_data,
					std::string(BulkData::*f)(type_of_mesh_part, int)) noexcept;
							
				
				private:	void add_line_of_text_to_nastran_file(string line) noexcept;
				///////////////////////////////////////////////////////////////
				
				//Set State Of Nastran Version Functions//////////////////////
				private:	void set_default_state() noexcept;
				public:		void set_state_of_nastran_version(Type_Of_Nastran_Version type) noexcept;
				///////////////////////////////////////////////////////////////

				};
				template<class type_of_mesh_part>
				inline void NastranExporter::set_block_of_bulk_data( 
					std::vector<type_of_mesh_part> const& mesh_data, 
					std::string(BulkData::*f)(type_of_mesh_part, int)) noexcept
				{
					auto index{ 1 };
					for (auto mesh_part : mesh_data)
					{
						os << (bulkData->*f)(mesh_part, index) << std::endl;
						index++;
					}
				}
			}
		}
	}
}


#endif //CPP_NASTRANEXPORTER_H