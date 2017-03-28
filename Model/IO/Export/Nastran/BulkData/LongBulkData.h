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
					class LongBulkData :public BulkData
					{
					public:
						LongBulkData();
						~LongBulkData();

					public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) override;
					public: string virtual get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID) override;
					public: string virtual get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID) override;
					};
				}
			}
		}
	}
}

