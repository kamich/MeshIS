//*************************
//Created by Dominik Kopaczka
//*************************

#include "LongBulkData.h"

using namespace MeshIS::Model::Export::Nastran::BData;

LongBulkData::LongBulkData()
{
}


LongBulkData::~LongBulkData()
{
}

string LongBulkData::get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID)
{
	return string();
}

string LongBulkData::get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 elementT4, int elementID)
{
	return string();
}

string LongBulkData::get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 elementP6, int elementID)
{
	return string();
}
