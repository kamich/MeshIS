#include <iostream>
#include <fstream>
#include <string>
#include "../../MeshExporter.h"
#include "../../../../Common/CommonMeshRepresentation.h"
#define MESHIS_COMMON_MESH_REPRESENTATION_H_
#define MESHIS_MESH_EXPORTER_H_

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Vertex;

class MeshExport : public MeshIS::Model::Export::MeshExporter {
private:
	std::fstream file;
public:
	void Export(const string& absolute_file_path, const CMR & mesh_data) {
		file.open(absolute_file_path, std::ios::out);
		if (file.good()) {
			file << "$MeshFormat" << std::endl << "2.2 0 8" << "$EndMeshFormat" << std::endl;
		}
	}
};