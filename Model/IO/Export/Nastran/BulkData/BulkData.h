//*************************
//Created by Dominik Kopaczka
//*************************

#include<string>
#include "../../../../Common/CommonMeshRepresentation.h"

using std::string;

#ifndef CPPWINLIN_BULKDATA_H
#define CPPWINLIN_BULKDATA_H


using std::string;
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
					class BulkData
					{
					public:
						BulkData();
						~BulkData();
					public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) = 0;
					public: string virtual get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID) = 0;
					public: string virtual get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID) = 0;
					};
				}
			}
		}
	}
}

#endif //CPP_BULKDATA_H