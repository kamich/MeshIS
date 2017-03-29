//
// Created by Kiełbasa Karol on 28.03.2017.
//

#include "FreeBulkData.h"
#include "../../../../Common/CommonMeshRepresentation.h"


FreeBulkData::FreeBulkData() {
}


FreeBulkData::~FreeBulkData() {
}

string FreeBulkData::get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) {
    string GRID{ "GRID" };

    GRID = GRID
           + "," + std::to_string(vertexID)
           + "," + "0"
           + "," + std::to_string(vertex[0])
           + "," + std::to_string(vertex[1])
           + "," + std::to_string(vertex[2]);

    return GRID;
}

string FreeBulkData::get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 element_t4, int elementID) {
    string CTETRA{ "CTETRA" };

    CTETRA = CTETRA
             + "," + std::to_string(elementID)
             + "," + "3"
             + "," + std::to_string(element_t4[0])
             + "," + std::to_string(element_t4[1])
             + "," + std::to_string(element_t4[2])
             + "," + std::to_string(element_t4[3]);

    return CTETRA;
}

string FreeBulkData::get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 element_p6, int elementID) {
    string CPENTA{ "CPENTA" };

    CPENTA = CPENTA
             + "," + std::to_string(elementID)
             + "," + "1"
             + "," + std::to_string(element_p6[0])
             + "," + std::to_string(element_p6[1])
             + "," + std::to_string(element_p6[2])
             + "," + std::to_string(element_p6[4])
             + "," + std::to_string(element_p6[5]);
    return  CPENTA;
}