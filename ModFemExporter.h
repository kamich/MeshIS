#ifndef ABAQUSEXPORTER_ABAQUSEXPORTER_H
#define ABAQUSEXPORTER_ABAQUSEXPORTER_H

#include "Model/Common/CommonMeshRepresentation.h"
#include "Model/IO/Export/MeshExporter.h"
#include "helperMethods.h"



using std::string;
using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T4;


class ModFemExporter: public MeshIS::Model::Export::MeshExporter{
public:

    void Export(const string& absolute_file_path,const CMR & mesh_data);

private:
    std::string getSeparator(double number){ return number<0?"-":" "; }
    void writeToFile(const string &absolute_file_path, const CMR &mesh_data);
    void printElements(std::fstream & file, const CMR &mesh_data);
    void printVertexes(std::fstream &file, const CMR &mesh_data);
    void printEdges(std::fstream &file, const CMR &mesh_data);
    void printFaces(std::fstream &file, const CMR &mesh_data);

};


#endif //ABAQUSEXPORTER_ABAQUSEXPORTER_H
