//*************************
//Created by Dominik Kopaczka
//*************************

#ifndef CPP_SHORTBULKDATA_H
#define CPP_SHORTBULKDATA_H

#include"BulkData.h"

namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{
			namespace Nastran
			{
				namespace BData
				{
					/*
						ShortBulkData inherits after abstract class BulkData
					*/
					class ShortBulkData :public BulkData
					{
						//Virtual Methods Returning Line Of Bulk Data//////////////////////

						//First method is not virtual but it is strongly related with another 
						//virtual methods(It is the template body methods:get_GRID,get_CTETRA,get_CPENTA).
						private:	
							template<class type_of_mesh_part>
							decltype(auto) get_line_from_mesh_part(
							type_of_mesh_part mesh_part, 
							int ID) noexcept;

						public:		string virtual	get_GRID_line_from_vertex(
							Vertex vertex,
							int vertexID) override final;
						public:		string virtual	get_CTETRA_line_from_elementT4(
							Element_T4 elementT4,
							int elementID) override final;
						public:		string virtual	get_CPENTA_line_from_elementP6(
							Element_P6 elementP6,
							int elementID) override final;
						///////////////////////////////////////////////////////////////////
						
					
						//Method set IDs///////////////////////////////////////////////////

						private:	void set_id(string& line, int ID) noexcept;
						private:	void set_number_of_PSOLID(string& line, int PSOLID_ID) noexcept;
						///////////////////////////////////////////////////////////////////

						//Methods Adding Parametrs Mesh To Result Line Of Short Bulk Data//
						private:
							template<class type_of_mesh_part>
							void add_all_variable_to_line(type_of_mesh_part mesh_part, string& line) noexcept;

						private:
							template<typename type_of_variable>
							void add_variable_to_line(type_of_variable variable, string& line) noexcept;

						private:	decltype(auto) set_cell_from_string(string some_string) noexcept;
						private:    void set_string_according_to_its_length(string& some_string, int length) noexcept;
						private:    void fill_out_spaces(string& some_string, int length) noexcept;
						///////////////////////////////////////////////////////////////////
					};
				}
			}
		}
	}
}

#endif //CPPWINLIN_SHORTBULKDATA_H