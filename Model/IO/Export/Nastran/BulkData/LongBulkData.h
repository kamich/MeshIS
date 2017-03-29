//
// Created by Kiełbasa Karol on 28.03.2017.
//

#ifndef CPPWINLIN_LONGBULKDATA_H
#define CPPWINLIN_LONGBULKDATA_H

#pragma once
#include"BulkData.h"
class LongBulkData :public BulkData
{
public:
    LongBulkData();
    ~LongBulkData();

public:  virtual string get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) override;
public:  virtual string get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID) override;
public:  virtual string get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID) override;
};

#endif //CPP_LONGBULKDATA_H
