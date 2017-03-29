//
// Created by Kiełbasa Karol on 28.03.2017.
//

#pragma once
#include<string>
#include "../../../../Common/CommonMeshRepresentation.h"

using std::string;

#ifndef CPPWINLIN_BULKDATA_H
#define CPPWINLIN_BULKDATA_H

class BulkData
{
public:
    BulkData();
    ~BulkData();
public:  virtual string get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) = 0;
public:  virtual string get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID) = 0;
public:  virtual string get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID) = 0;
};


#endif //CPP_BULKDATA_H
