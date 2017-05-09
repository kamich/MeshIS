#pragma once
#include <fstream>
#include "CommonMeshRepresentation.h"
#include "MeshExporter.h"



class VTK_Exporter : public MeshIS::Model::Export::MeshExporter {
private:
	std::fstream VTK_file;

	void exportHeader();
	void exportPoints(const CMR & mesh_data);
	void exportCells(const CMR & mesh_data);
	void exportCellTypes(const CMR & mesh_data);
public:
	void Export(const string& absolute_file_path, const CMR & mesh_data);
};