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

CMR MeshIS::Model::Import::NastranMeshImporter::parse(stringstream & stream)
{
    CMR mesh;
    {
        string  temp;
        while (getline(stream, temp)) {
            stringstream cache_sstream(temp);
            char token_buffer[COLUMN_LENGTH] = {};

            cache_sstream.read(token_buffer, COLUMN_LENGTH);
            string token(token_buffer, COLUMN_LENGTH);
            chrom::erase_all_spaces(token);

            parser->choose_parser(token, cache_sstream, mesh);

            temp.clear();
        }
    }

    shrink_to_fit_containers(mesh);
    return move(mesh);
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
        parser = std::make_unique<BdfParser>();
        break;
    default:
        parser = std::make_unique<NasParser>();
    }
}
