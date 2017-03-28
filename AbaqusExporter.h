#ifndef ABAQUSEXPORTER_ABAQUSEXPORTER_H
#define ABAQUSEXPORTER_ABAQUSEXPORTER_H

#include "Model/Common/CommonMeshRepresentation.h"
#include "Model/IO/Export/MeshExporter.h"



using std::string;
using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Vertex;

class AbaqusExporter: public MeshIS::Model::Export::MeshExporter{
public:

    void Export(const string& absolute_file_path,const CMR & mesh_data);

private:
    std::string getSeparator(double number){ return number<0?"-":" "; }
    void printElements(std::fstream & file,vector<Element_T4> elements);
    void printVertexes(std::fstream & file,vector<Vertex> vertexes);
    void printInformation(std::fstream & file,vector<std::string> information);
};


#endif //ABAQUSEXPORTER_ABAQUSEXPORTER_H
