//*************************
//Created by Dominik Kopaczka
//*************************

#include "ShortBulkData.h"

using namespace MeshIS::Model::Export::Nastran::BData;

template<class type_of_mesh_part>
decltype(auto) ShortBulkData::get_line_from_mesh_part(
	type_of_mesh_part mesh_part, 
	int ID) noexcept
{
	string line{ "" };
	set_id(line, ID);
	set_number_of_PSOLID(line, 0);
	add_all_variable_to_line(mesh_part, line);
	return line;
}

string ShortBulkData::get_GRID_line_from_vertex(
	Vertex vertex,
	int vertexID) 
{
	string GRID_line{ "GRID    " };
	return GRID_line + get_line_from_mesh_part(vertex, vertexID);
}

string ShortBulkData::get_CTETRA_line_from_elementT4(
	Element_T4 elementT4,
	int elementID)
{
	string CTETRA_line{ "CTETRA  " };
	return CTETRA_line + get_line_from_mesh_part(elementT4, elementID);
}

string ShortBulkData::get_CPENTA_line_from_elementP6(
	Element_P6 elementP6, 
	int elementID) 
{
	string CPENTA_line{ "CPENTA  " };
	return CPENTA_line+ get_line_from_mesh_part(elementP6, elementID);
}

void ShortBulkData::set_id(
	string & line, 
	int ID) noexcept
{
	add_variable_to_line(ID, line);
}

void ShortBulkData::set_number_of_PSOLID(
	string & line, 
	int PSOLID_ID) noexcept
{
	add_variable_to_line(PSOLID_ID, line);
}

template<class type_of_mesh_part>
void ShortBulkData::add_all_variable_to_line(
	type_of_mesh_part mesh_part, 
	string & line) noexcept
{
	for (auto variable : mesh_part)
		add_variable_to_line(variable, line);
}

template<typename type_of_variable>
void ShortBulkData::add_variable_to_line(
	type_of_variable variable, 
	string & line) noexcept
{
	auto string_from_variable{ std::to_string(variable) };
	line += set_cell_from_string(string_from_variable);
}

decltype(auto) ShortBulkData::set_cell_from_string(
	string some_string) noexcept
{
	auto number_of_digits{ some_string.length() };
	set_string_according_to_its_length(some_string, number_of_digits);
	return some_string;
}

void MeshIS::Model::Export::Nastran::BData::ShortBulkData::set_string_according_to_its_length(
	string & some_string,
	int length) noexcept
{
	if (length > 8)
		some_string.resize(8);
	else
		fill_out_spaces(some_string, length);
}

void MeshIS::Model::Export::Nastran::BData::ShortBulkData::fill_out_spaces(
	string & some_string, 
	int length) noexcept
{
	auto number_of_spaces = 8 - length;
	while (number_of_spaces)
	{
		some_string += " ";
		number_of_spaces--;
	}
}