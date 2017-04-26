#pragma once
#include <vector>
#include <array>
#include <unordered_map>
#include <sstream>
#include <locale>
#include "MeshImporter.h"
#include "FileManager.h"
#include "CommonMeshRepresentation.h"

using MeshIS::Model::Common::CMR;
using std::unordered_map;
using std::stringstream;
using std::string;
using std::vector;
using std::array;

namespace MeshIS
{
	namespace Model
	{
		namespace Import
		{
			class NastranMeshImporter : public MeshImporter
			{
				using function_map = unordered_map<string, void(NastranMeshImporter::*)(stringstream&, CMR&)>;

				static constexpr int COLUMN_LENGTH = 8;
				function_map line_parsers;

				CMR parse(stringstream& stream);
				void bdf_parse_grid_point(stringstream & stream, CMR & mesh);
				void bdf_parse_ctria3_face(stringstream & stream, CMR & mesh);
				void bdf_parse_cquad4_face(stringstream & stream, CMR & mesh);
				void bdf_parse_cpenta_volume(stringstream & stream, CMR & mesh);
				

				void erase_all_spaces(string & field);
				string convert_chunk_to_string(stringstream & stream);
				void shrink_to_fit_containers(CMR & mesh);

			public:
				virtual CMR   Import(const string & absolute_file_path);
			};

		}//! end of namespace Import
	}//! end of namespace Model
}//! end of namespace MeshIS