#include "LongBulkData.h"

using namespace MeshIS::Model::Export::Nastran::BData;

LongBulkData::LongBulkData() {
}


LongBulkData::~LongBulkData() {
}

string LongBulkData::get_GRID_line_from_vertex(MeshIS::Model::Common::Vertex vertex, int vertexID) {
	stringstream gridStream;
	gridStream << "GRID*" << setw(8) << std::to_string(vertexID)
		<< setw(16) << "0"
		<< setw(16) << std::to_string(vertex[0])
		<< setw(16) << std::to_string(vertex[1])
		<< setw(8) << "*N" << std::to_string(vertexID)
		<< setw(8) << "*N" << std::to_string(vertexID)
		<< setw(16) << std::to_string(vertex[2]);

	return gridStream.str();
}

string LongBulkData::get_CTETRA_line_from_elementT4(MeshIS::Model::Common::Element_T4 element_t4, int elementID) {
	stringstream ctetraStream;
	ctetraStream << "CTETRA" << setw(8) << std::to_string(elementID)
		<< setw(8) << "3"
		<< setw(8) << std::to_string(element_t4[0])
		<< setw(8) << std::to_string(element_t4[1])
		<< setw(8) << std::to_string(element_t4[2])
		<< setw(8) << std::to_string(element_t4[3]);

	return ctetraStream.str();
}

string LongBulkData::get_CPENTA_line_from_elementP6(MeshIS::Model::Common::Element_P6 element_p6, int elementID) {
	stringstream cpentaStream;
	cpentaStream << "CPENTA" << setw(8) << std::to_string(elementID)
		<< setw(8) << "1"
		<< setw(8) << std::to_string(element_p6[0])
		<< setw(8) << std::to_string(element_p6[1])
		<< setw(8) << std::to_string(element_p6[2]);
		<< setw(8) << std::to_string(element_p6[3]);
		<< setw(8) << std::to_string(element_p6[4]);
		<< setw(8) << std::to_string(element_p6[5]);

	return cpentaStream.str();
}

