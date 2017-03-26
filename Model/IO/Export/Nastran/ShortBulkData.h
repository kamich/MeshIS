#pragma once
#include"BulkData.h"
class ShortBulkData :public BulkData
{
public:
	ShortBulkData();
	~ShortBulkData();
public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CTETRA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CPENTA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
};

