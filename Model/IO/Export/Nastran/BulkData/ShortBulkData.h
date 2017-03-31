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
					#pragma region Constructors
						public:		ShortBulkData();
					#pragma endregion

					#pragma region Destructor
						public:		~ShortBulkData();
					#pragma endregion

					#pragma region Virtual Methods Returning Line Of Bulk Data
						//First method is not virtual but is  but it is strongly related with another 
						//virtual methods.
						private:	
							template<class type_of_mesh_part>
							decltype(auto) get_line_from_mesh_part(
							type_of_mesh_part mesh_part, 
							int ID);

						public:		string virtual	get_GRID_line_from_vertex(
							MeshIS::Model::Common::Vertex vertex,
							int vertexID) override;

						public:		string virtual	get_CTETRA_line_from_elementT4(
							MeshIS::Model::Common::Element_T4 elementT4,
							int elementID) override;

						public:		string virtual	get_CPENTA_line_from_elementP6(
							MeshIS::Model::Common::Element_P6 elementP6,
							int elementID) override;

						
					#pragma endregion

					#pragma region Method Set IDs
						//Set id vertex or element to result nastran file
						private:	void set_id(string& line, int ID);
						//Set id vertex or element to result nastran file
						private:	void set_number_of_PSOLID(string& line, int PSOLID_ID);
					#pragma endregion

					#pragma region Methods Adding Parametrs Mesh To Result String
						private:
							template<class type_of_mesh_part>
							void add_all_variable_to_line(type_of_mesh_part mesh_part, string& line);

						private:
							template<typename type_of_variable>
							void add_variable_to_line(type_of_variable variable, string& line);

						private:	decltype(auto) set_cell_from_string(string some_string);

						private:    void set_string_according_to_its_length(string& some_string, int length);

						private:    void fill_out_spaces(string& some_string, int length);
					#pragma endregion
					};
				}
			}
		}
	}
}

#endif //CPPWINLIN_SHORTBULKDATA_H