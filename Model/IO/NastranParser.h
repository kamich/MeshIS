#pragma
#ifndef NASTRAN_PARSER_H_
#define NASTRAN_PARSER_H_

#include <vector>
#include <array>
#include <unordered_map>
#include <sstream>
#include <cctype>
#include "CommonMeshRepresentation.h"
#include "NastranSHORT.h"

using MeshIS::Model::Common::CMR;
using std::unordered_map;
using std::stringstream;
using std::string;
using std::vector;
using std::array;

class NastranShortParser
{
	using function_map = unordered_map<string, void(NastranShortParser::*)(stringstream&, CMR&)>;

	static constexpr int COLUMN_LENGTH = 8;
	function_map line_parsers;
	stringstream cache_sstream;

	//.bdf
	void bdf_parse_grid_point(stringstream & stream, CMR & mesh);
	void bdf_parse_ctria3_face(stringstream & stream, CMR & mesh);
	void bdf_parse_cquad4_face(stringstream & stream, CMR & mesh);
	void bdf_parse_cpenta_volume(stringstream & stream, CMR & mesh);

	//.nas
	void nas_parse_grid_point(stringstream & stream, CMR & mesh);
	void nas_parse_ctriax_face(stringstream & stream, CMR & mesh);
	void nas_parse_ctetra_volume(stringstream & stream, CMR & mesh);

	void erase_all_spaces(string & field);

	string convert_chunk_to_string(stringstream & stream);
	void clean_cache_sstream();
	//void shrink_to_fit_containers(CMR & mesh);

public:
	CMR parse(stringstream& stream);

	NastranShortParser(NastranSHORT file_type);
};
#endif // !NASTRAN_PARSER_H_