//
// Created by lordkopakos on 2017-03-17.
//

//#ifndef PROJECTCPP_NASTRANEXPORTER_H
//#define PROJECTCPP_NASTRANEXPORTER_H
#pragma once

#include "MeshExporter.h"
#include<iostream>
#include<fstream>
#include <iterator>
#include<vector>

using std::string;

namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{
			namespace Nastran
			{
				class NastranExporter : public MeshIS::Model::Export::MeshExporter {

				public:     enum class Type_Of_Nastran_Version {
					FREE,
					SHORT,
					LONG
				};

				public:		enum class Type_Of_Method_Continuation {
					PLUS_FILED,
					STAR_FILED,
					BLANK_FIELD
				};

				private:	string absolute_file_path;

				private:    Type_Of_Nastran_Version state_of_nastran_version;
				private:	Type_Of_Method_Continuation state_of_continuation_entrie;
				private:	short int gap;

				public:     NastranExporter();
				public:     NastranExporter(Type_Of_Nastran_Version type_of_nastran, Type_Of_Method_Continuation state_of_continuation_entrie);


				public:		void virtual Export(const string& absolute_file_path, const MeshIS::Model::Common::CMR& mesh_data);
				private:	void set_absolute_file_path(const string& absolute_file_path);
				private:    vector<string> create_nastran_file_from_CMR(const MeshIS::Model::Common::CMR & mesh_data);
				
				private:	void create_bulk_data(const MeshIS::Model::Common::CMR & mesh_data);
				private:	void set_GRID(const MeshIS::Model::Common::CMR & mesh_data);
				private:	void set_CTETRA(const MeshIS::Model::Common::CMR & mesh_data);
				private:	void set_CPENTA(const MeshIS::Model::Common::CMR & mesh_data);

				private:    void set_gap();

				private:	void set_default_state();
				};
			}
		}
	}
}
