#pragma once
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

						private:	string set_cell_from_string(string some_string);
					#pragma endregion

					#pragma region Virtual Methods Returning Line Of Bulk Data
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
					};
				}
			}
		}
	}
}
