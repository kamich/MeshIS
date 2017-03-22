#include "NastranParser.h"

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;
using MeshIS::Model::Common::Element_T3;
using MeshIS::Model::Common::Element_Q4;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;

CMR NastranShortParser::parse(stringstream & stream)
{
	string  temp;
	char token_buffer[COLUMN_LENGTH];
	auto const not_found = line_parsers.cend();
	CMR mesh;

	while (getline(stream, temp)) {
		cache_sstream << temp;
		cache_sstream.read(token_buffer, COLUMN_LENGTH);
		string token(token_buffer, COLUMN_LENGTH);
		erase_all_spaces(token);
		
		const auto parser = line_parsers.find(token);
		if (parser == not_found) {
			clean_cache_sstream();
			continue;
		}
		
		(this->*(parser->second))(cache_sstream, mesh);
		clean_cache_sstream();
	}

	return std::move(mesh);
}

void NastranShortParser::bdf_parse_grid_point(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Vertex vertex;
	for (auto& coordinate : vertex) {
		const string column = convert_chunk_to_string(stream);
		coordinate = std::stod(column);	//TODO shift ids by 1?
	}

	mesh.vertices.push_back(std::move(vertex));
}

void NastranShortParser::bdf_parse_ctria3_face(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_T3 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = std::stoi(column);
	}

	mesh.elementsT3.push_back(std::move(element));
}

void NastranShortParser::bdf_parse_cquad4_face(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_Q4 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = std::stoi(column);
	}

	mesh.elementsQ4.push_back(std::move(element));
}

void NastranShortParser::bdf_parse_cpenta_volume(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_P6 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = std::stoi(column);
	}

	mesh.elementsP6.push_back(std::move(element));
}

void NastranShortParser::nas_parse_grid_point(stringstream & stream, CMR & mesh)
{
	stream.ignore(COLUMN_LENGTH, ' ');

	Vertex vertex;
	for (auto& coordinate : vertex) {
		stream >> coordinate;
	}

	mesh.vertices.push_back(std::move(vertex));
}

void NastranShortParser::nas_parse_ctriax_face(stringstream & stream, CMR & mesh)
{
	stream.ignore(COLUMN_LENGTH, ' ');
	stream.ignore(COLUMN_LENGTH, ' ');

	Element_T3 element;
	for (auto& vertex_id : element) {
		stream >> vertex_id;
	}

	mesh.elementsT3.push_back(std::move(element));
}

void NastranShortParser::nas_parse_ctetra_volume(stringstream & stream, CMR & mesh)
{
	stream.ignore(COLUMN_LENGTH, ' ');
	stream.ignore(COLUMN_LENGTH, ' ');

	Element_T4 element;
	for (auto&vertex_id : element) {
		stream >> vertex_id;
	}

	mesh.elementsT4.push_back(std::move(element));
}

void NastranShortParser::erase_all_spaces(std::string & field)
{
	field.erase(std::remove_if(field.begin(), field.end(), ::isspace), field.end());
}

std::string NastranShortParser::convert_chunk_to_string(std::stringstream & stream)
{
	char chunk_buffer[COLUMN_LENGTH];

	stream.read(chunk_buffer, COLUMN_LENGTH);
	std::string column(chunk_buffer, COLUMN_LENGTH);
	erase_all_spaces(column);
	return column;
}

void NastranShortParser::clean_cache_sstream()
{
	cache_sstream.str("");
}

NastranShortParser::NastranShortParser(NastranSHORT file_type) :
	cache_sstream()
{
	switch (file_type)
	{
	case NastranSHORT::BDF:
		line_parsers = {
			{ "GRID", &NastranShortParser::bdf_parse_grid_point },
			{ "CTRIA3", &NastranShortParser::bdf_parse_ctria3_face },
			{ "CQUAD4", &NastranShortParser::bdf_parse_cquad4_face },
			{ "CPENTA", &NastranShortParser::bdf_parse_cpenta_volume }
		};
		break;
	default:
		line_parsers = {
			{ "GRID", &NastranShortParser::nas_parse_grid_point },
			{ "CTRIAX", &NastranShortParser::nas_parse_ctriax_face },
			{ "CTETRA", &NastranShortParser::nas_parse_ctetra_volume }
		};
	}
}