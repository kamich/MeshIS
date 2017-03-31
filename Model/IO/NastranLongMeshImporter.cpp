#include "NastranLongMeshImporter.h"

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;
using MeshIS::Model::Common::Element_T3;
using MeshIS::Model::Common::Element_Q4;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;

using boost::filesystem::path;

using std::getline;
using std::move;
using std::stoi;
using std::stod;
using std::remove_if;

CMR MeshIS::Model::Import::NastranMeshImporter::parse(stringstream & stream)
{
	string  temp;
	CMR mesh;
	auto const not_found = line_parsers.cend();

	while (getline(stream, temp)) {
		stringstream cache_sstream(temp);
		char token_buffer[COLUMN_LENGTH] = {};

		cache_sstream.read(token_buffer, COLUMN_LENGTH);
		string token(token_buffer, COLUMN_LENGTH);
		erase_all_spaces(token);

		const auto parser = line_parsers.find(token);
		if (parser != not_found)
			(this->*(parser->second))(cache_sstream, mesh);

		temp.clear();
	}

	shrink_to_fit_containers(mesh);
	return move(mesh);
}

void MeshIS::Model::Import::NastranMeshImporter::bdf_parse_grid_point(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Vertex vertex;
	for (auto& coordinate : vertex) {
		const string column = convert_chunk_to_string(stream);
		coordinate = stod(column);
	}

	mesh.vertices.push_back(move(vertex));
}

void MeshIS::Model::Import::NastranMeshImporter::bdf_parse_ctria3_face(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_T3 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = stoi(column);
	}

	chrom::decrement_values(element);
	mesh.elementsT3.push_back(move(element));
}

void MeshIS::Model::Import::NastranMeshImporter::bdf_parse_cquad4_face(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_Q4 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = stoi(column);
	}

	chrom::decrement_values(element);
	mesh.elementsQ4.push_back(move(element));
}

void MeshIS::Model::Import::NastranMeshImporter::bdf_parse_cpenta_volume(stringstream & stream, CMR & mesh)
{
	stream.ignore(2 * COLUMN_LENGTH);

	Element_P6 element;
	for (auto& vertex_id : element) {
		const string column = convert_chunk_to_string(stream);
		vertex_id = stoi(column);
	}

	chrom::decrement_values(element);
	mesh.elementsP6.push_back(move(element));
}