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
					class ShortBulkData :public BulkData
					{
						//Virtual Methods Returning Line Of Bulk Data//////////////////////
						public:		string virtual	get_GRID_line_from_vertex(Vertex vertex, int vertexID) override final;
						public:		string virtual	get_CTETRA_line_from_elementT4(Element_T4 elementT4, int elementID) override final;
						public:		string virtual	get_CPENTA_line_from_elementP6(Element_P6 elementP6, int elementID) override final;
						///////////////////////////////////////////////////////////////////

						//Function templates/////////////////////////////////////////////// 
						//It is the template body methods:get_GRID,get_CTETRA,get_CPENTA.
						private:	
							template<class type_of_mesh_part>
							decltype(auto) get_line_from_mesh_part(type_of_mesh_part mesh_part, int ID) noexcept;

						//Method Adding Variables Mesh To Result Line Of Short Bulk Data//
						private:
							template<class type_of_mesh_part>
							void add_all_mesh_part_variable_to_line(type_of_mesh_part mesh_part, string& line) noexcept;
						///////////////////////////////////////////////////////////////////

					};
				}
			}
		}
	}
}

#endif //CPPWINLIN_SHORTBULKDATA_H