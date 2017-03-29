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
public:
	void Export(const string& absolute_file_path, const CMR & mesh_data) {
		std::fstream file.open(absolute_file_path, std::ios::out);
		if (file.good()) {
			file << "$MeshFormat" << std::endl << "2.2 0 8" << "$EndMeshFormat" << std::endl;
			addSurface(file, mesh_data);
			addNodes(file, mesh_data);
			addElements(file, mesh_data);
		}
	}

	void addSurface(std::fstream &file, const CMR &mesh_data) {
		file << "$PhysicalNames" << std::endl;
		file << surfaceVector.size() + 1 << std::endl;
		for (int i = 0; i < surfaceVector.size(); i++){
			file << i + 1 << " " << surfaceVector[i] << std::endl;
		}
		file << "$EndPhysicalNames" << std::endl;
	}

	void addNodes(std::fstream &file, const CMR &mesh_data) {
		file << "$Nodes" << std::endl << mesh_data.vertices.size() + 1;
		for (int i = 0; i < mesh_data.vertices.size(); i++){
			file << i + 1;
			for (const auto &vertex : mesh_data.vertices[i])
				file << " " << std::uppercase << std::scientific << vertex;
			file << std::endl;
		}
		file << "$EndNodes" << std::endl;
	}

	void addElements(std::fstream &file, const CMR &mesh_data) {
		file << "$Elements" << std::endl;
		file << mesh_data.elementsT4.size() << std::endl;
		for (int i = 0; i < mesh_data.elementsT4.size(); i++){
			file << i + 1;
			for (const auto &el : mesh_data.elementsT4[i]) {
				
			}
			file << std::endl;
		}
		file << "$EndElements" << std::endl;
	}
};