#pragma once
#include<string>
#include"CommonMeshRepresentation.h"

using std::string;

class BulkData
{
public:
	BulkData();
	~BulkData();
public: string virtual get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex) = 0;
public: string virtual get_CTETRA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) = 0;
public: string virtual get_CPENTA_line_from_vertex(MeshIS::Model::Common::Vertex vertex) = 0;
};

