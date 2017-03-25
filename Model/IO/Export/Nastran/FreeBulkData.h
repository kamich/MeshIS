#pragma once
#include"BulkData.h"
class FreeBulkData :public BulkData
{
public:
	FreeBulkData();
	~FreeBulkData();
public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CTETRA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
public: string virtual get_CPENTA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) override;
};

