#pragma once
#include <fstream>
#include "CommonMeshRepresentation.h"
#include "MeshExporter.h"



class VTK_Exporter : public MeshIS::Model::Export::MeshExporter {
private:
	std::fstream VTK_file;
public:
	void Export(const string& absolute_file_path, const CMR & mesh_data);
};