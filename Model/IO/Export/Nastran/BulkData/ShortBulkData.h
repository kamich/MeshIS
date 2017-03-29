//
// Created by Kiełbasa Karol on 28.03.2017.
//

#ifndef CPP_SHORTBULKDATA_H
#define CPP_SHORTBULKDATA_H
#pragma once
#include"BulkData.h"
class ShortBulkData :public BulkData
{

public:		ShortBulkData();
public:		~ShortBulkData();


public:		string virtual	get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) override;

private:	void set_id(string& GRID_line, int vertexID);
private:	void set_number_of_PSOLID(string& GRID_line, int PSOLID_ID);

private:
    template<class type_of_mesh_part>
    void add_all_variable_to_line(type_of_mesh_part mesh_part, string& line);

    template<typename type_of_variable>
    void add_variable_to_line(type_of_variable variable, string& line);

private:	string set_cell_from_string(string some_string);



public:		string virtual	get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID) override;



public:		string virtual	get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID) override;
};
#endif //CPPWINLIN_SHORTBULKDATA_H