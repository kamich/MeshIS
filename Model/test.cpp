//
// Created by Panda on 31.03.2017.
//
#include <iostream>
#include "Common/CommonMeshRepresentation.h"
#include "Mesh Statistics/MeshStatistics.h"
using namespace MeshIS::Model;



int main() {
    CMR cmr;
    Vertex vertex1={0,0,0};
    Vertex vertex2={1,1,1};
    Vertex vertex3={0,1,1};
    Element_T3 element={1,2,3};
    cmr.vertices.push_back(vertex1);
    cmr.vertices.push_back(vertex2);
    cmr.vertices.push_back(vertex3);
    cmr.elementsT3.push_back(element);

    MS ms=MS(cmr);
    ms.processT3Elements();

    std::cout<<ms.avgT3Ratio<<std::endl;

}
