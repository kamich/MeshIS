#include <iostream>
#include "AbaqusExporter.h"
#include "Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;





vector<Vertex> vertexes;
vector<Element_T4> elements;
CMR cmr;
void loadElements();

int main() {
    AbaqusExporter abaqusExporter;
    loadElements();
    //abaqusExporter.exportToAbaqus("test.inp",vertexes,elements);
    abaqusExporter.Export("test.inp",cmr);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void loadElements(){
    Vertex vertex1={-2.000000029E-01,1.212498173E-01,2.657158076E-01};
    Vertex vertex2={-2.000000029E-01,9.395208954E-02,3.363113999E-01};
    Vertex vertex3={-2.000000029E-01,1.533117890E-01,3.211169242E-01};
    Vertex vertex4={-2.000000029E-01, 5.846185237E-02,2.813982963E-01};


    Element_T4 element={1,2,3,4};

    cmr.vertices.push_back(vertex1);
    cmr.vertices.push_back(vertex2);
    cmr.vertices.push_back(vertex3);
    cmr.vertices.push_back(vertex4);

    cmr.elementsT4.push_back(element);
}