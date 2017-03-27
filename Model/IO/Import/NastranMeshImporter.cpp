#include "NastranMeshImporter.h"

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

void MeshIS::Model::Import::NastranMeshImporter::nas_parse_grid_point(stringstream & stream, CMR & mesh)
{
    stream.ignore(COLUMN_LENGTH);

    Vertex vertex;
    for (auto& coordinate : vertex) {
        stream >> coordinate;
    }

    mesh.vertices.push_back(move(vertex));
}

void MeshIS::Model::Import::NastranMeshImporter::nas_parse_ctriax_face(stringstream & stream, CMR & mesh)
{
    stream.ignore(2 * COLUMN_LENGTH);

    Element_T3 element;
    for (auto& vertex_id : element) {
        stream >> vertex_id;
    }

    chrom::decrement_values(element);
    mesh.elementsT3.push_back(move(element));
}

void MeshIS::Model::Import::NastranMeshImporter::nas_parse_ctetra_volume(stringstream & stream, CMR & mesh)
{
    stream.ignore(2 * COLUMN_LENGTH);

    Element_T4 element;
    for (auto&vertex_id : element) {
        stream >> vertex_id;
    }

    chrom::decrement_values(element);
    mesh.elementsT4.push_back(move(element));
}

void MeshIS::Model::Import::NastranMeshImporter::erase_all_spaces(string & field)
{
    field.erase(remove_if(field.begin(), field.end(), [](char ch) { 
        return std::isspace<char>(ch, std::locale::classic()); 
    }), field.end());
}

string MeshIS::Model::Import::NastranMeshImporter::convert_chunk_to_string(stringstream & stream)
{
    char chunk_buffer[COLUMN_LENGTH];

    stream.read(chunk_buffer, COLUMN_LENGTH);
    std::string column(chunk_buffer, COLUMN_LENGTH);
    erase_all_spaces(column);
    return column;
}

void MeshIS::Model::Import::NastranMeshImporter::shrink_to_fit_containers(CMR & mesh)
{
    mesh.elementsP6.shrink_to_fit();
    mesh.elementsQ4.shrink_to_fit();
    mesh.elementsT3.shrink_to_fit();
    mesh.elementsT4.shrink_to_fit();
    mesh.vertices.shrink_to_fit();
}

CMR MeshIS::Model::Import::NastranMeshImporter::Import(const string & absolute_file_path)
{
    path file_path(absolute_file_path);
    IO::FileManager manager({ ".nas", ".bdf" });
    auto file = manager.open_file(file_path);
    auto mapped_file = IO::FileManager::map_file_to_stringstream(file);

    return parse(mapped_file);
}

MeshIS::Model::Import::NastranMeshImporter::NastranMeshImporter(NastranFileType file_type)
{
    switch (file_type)
    {
    case NastranFileType::BDF:
        line_parsers = {
            { "GRID", &NastranMeshImporter::bdf_parse_grid_point },
            { "CTRIA3", &NastranMeshImporter::bdf_parse_ctria3_face },
            { "CQUAD4", &NastranMeshImporter::bdf_parse_cquad4_face },
            { "CPENTA", &NastranMeshImporter::bdf_parse_cpenta_volume } };
        break;
    default:
        line_parsers = {
            { "GRID", &NastranMeshImporter::nas_parse_grid_point },
            { "CTRIAX", &NastranMeshImporter::nas_parse_ctriax_face },
            { "CTETRA", &NastranMeshImporter::nas_parse_ctetra_volume }
        };
    }
}
