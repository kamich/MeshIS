#include "ShortBulkData.h"

using namespace MeshIS::Model::Export::Nastran::BData;

ShortBulkData::ShortBulkData()
{
}


ShortBulkData::~ShortBulkData()
{
}

string ShortBulkData::get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID)
{
	string GRID_line{ "GRID    " };
	set_id(GRID_line, vertexID);
	set_number_of_PSOLID(GRID_line,0);
	add_all_variable_to_line(vertex, GRID_line);
	return GRID_line;
}

void ShortBulkData::set_id(string & line, int ID)
{
	add_variable_to_line(ID, line);
}

void ShortBulkData::set_number_of_PSOLID(string & line, int PSOLID_ID)
{
	add_variable_to_line(PSOLID_ID, line);
}

template<class type_of_mesh_part>
void ShortBulkData::add_all_variable_to_line(type_of_mesh_part mesh_part, string & line)
{
	for (auto variable : mesh_part)
	{
		add_variable_to_line(variable, line);
	}
}

template<typename type_of_variable>
void ShortBulkData::add_variable_to_line(type_of_variable variable, string & line)
{
	auto string_from_variable{ std::to_string(variable) };
	line += set_cell_from_string(string_from_variable);
}

string ShortBulkData::set_cell_from_string(string some_string)
{
	auto number_of_digits{ some_string.length() };
	if (number_of_digits>8)
	{
		some_string.resize(8);
	}
	else
	{
		auto number_of_spaces = 8 - number_of_digits;
		while (number_of_spaces) 
		{
			some_string += " ";
			number_of_spaces--;
		}
	}
	return some_string;
}

string ShortBulkData::get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID)
{
	string CTETRA_line{ "CTETRA  " };
	set_id(CTETRA_line, elementID);
	set_number_of_PSOLID(CTETRA_line, 0);
	add_all_variable_to_line(elementT4, CTETRA_line);
	return CTETRA_line;
}

string ShortBulkData::get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID)
{
	string CPENTA_line{ "CPENTA  " };
	set_id(CPENTA_line, elementID);
	set_number_of_PSOLID(CPENTA_line, 0);
	add_all_variable_to_line(elementP6, CPENTA_line);
	return CPENTA_line;
}
