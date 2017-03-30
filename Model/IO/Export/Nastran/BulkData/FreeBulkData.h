//*************************
//Created by Karol Kiełbasa
//*************************

#ifndef CPP_FREEBULKDATA_H
#define CPP_FREEBULKDATA_H

#include "BulkData.h"

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
					class FreeBulkData :public BulkData
					{
					public:
						FreeBulkData();
						~FreeBulkData();
					public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex
						, int vertexID) override;
					public: string virtual get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 element_t4
						, int elementID) override;
					public: string virtual get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 element_p6
						, int elementID) override;
					};
				}
			}
		}
	}
}

#endif //CPP_FREEBULKDATA_H
