#include "NasParser.h"

using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;
using MeshIS::Model::Common::Element_T3;
using MeshIS::Model::Common::Element_Q4;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
using std::move;

void NasParser::parse_grid_point(stringstream & stream, CMR & mesh)
{
    stream.ignore(COLUMN_LENGTH);

    Vertex vertex;
    for (auto& coordinate : vertex) {
        stream >> coordinate;
    }

    mesh.vertices.push_back(move(vertex));
}

void NasParser::parse_triangular_face(stringstream & stream, CMR & mesh)
{
    stream.ignore(2 * COLUMN_LENGTH);

    Element_T3 element;
    for (auto& vertex_id : element) {
        stream >> vertex_id;
    }

    chrom::decrement_values(element);
    mesh.elementsT3.push_back(move(element));
}

void NasParser::parse_quadrilateral_face(stringstream & stream, CMR & mesh)
{
}

void NasParser::parse_tetra_volume(stringstream & stream, CMR & mesh)
{
    stream.ignore(2 * COLUMN_LENGTH);

    Element_T4 element;
    for (auto&vertex_id : element) {
        stream >> vertex_id;
    }

    chrom::decrement_values(element);
    mesh.elementsT4.push_back(move(element));
}

void NasParser::parse_penta_volume(stringstream & stream, CMR & mesh)
{
}

void NasParser::choose_parser(const string & token, stringstream & stream, CMR & mesh)
{
    if (token == "GRID") {
        parse_grid_point(stream, mesh);
    }
    else if (token == "CTRIAX") {
        parse_triangular_face(stream, mesh);
    }
    else if (token == "CTETRA") {
        parse_tetra_volume(stream, mesh);
    }
}
