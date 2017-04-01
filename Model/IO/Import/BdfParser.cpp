#include "BdfParser.h"

using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;
using MeshIS::Model::Common::Element_T3;
using MeshIS::Model::Common::Element_Q4;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
using std::move;
using std::stoi;
using std::stod;

void BdfParser::parse_grid_point(stringstream & stream, CMR & mesh)
{
    stream.ignore(2 * COLUMN_LENGTH);

    Vertex vertex;
    for (auto& coordinate : vertex) {
        const string column = convert_chunk_to_string(stream);
        coordinate = stod(column);
    }

    mesh.vertices.push_back(move(vertex));
}

void BdfParser::parse_triangular_face(stringstream & stream, CMR & mesh)
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

void BdfParser::parse_quadrilateral_face(stringstream & stream, CMR & mesh)
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

void BdfParser::parse_tetra_volume(stringstream & stream, CMR & mesh)
{
}

void BdfParser::parse_penta_volume(stringstream & stream, CMR & mesh)
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

string BdfParser::convert_chunk_to_string(stringstream & stream)
{
    char chunk_buffer[COLUMN_LENGTH];

    stream.read(chunk_buffer, COLUMN_LENGTH);
    string column(chunk_buffer, COLUMN_LENGTH);
    chrom::erase_all_spaces(column);
    return column;
}

void BdfParser::choose_parser(const string & token, stringstream & stream, CMR & mesh)
{
    if (token == "GRID") {
        parse_grid_point(stream, mesh);
    }
    else if (token == "CTRIA3") {
        parse_triangular_face(stream, mesh);
    }
    else if (token == "CQUAD4") {
        parse_quadrilateral_face(stream, mesh);
    }
    else if (token == "CPENTA") {
        parse_penta_volume(stream, mesh);
    }
}
