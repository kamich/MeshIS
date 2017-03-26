#pragma once
#include"BulkData.h"
class LongBulkData :public BulkData
{
public:
	LongBulkData();
	~LongBulkData();

public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CTETRA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CPENTA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
};

