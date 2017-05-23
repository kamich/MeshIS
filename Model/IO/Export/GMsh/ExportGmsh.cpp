#include <iostream>
#include <fstream>
#include <string>
#include "ExportGMsh.h"

	void MeshExport::Export(const string& absolute_file_path, const CMR & mesh_data) {
		std::fstream file;
		file.open(absolute_file_path, std::ios::out);
		if (file.good()) {
			file << "$MeshFormat\n2.2 0 8\n$EndMeshFormat" << std::endl;	// const format
			addSurface(file, mesh_data);
			addNodes(file, mesh_data);
			addElements(file, mesh_data);
		}
	}

	void MeshExport::addSurface(std::fstream &file, const CMR &mesh_data) {
		file << "$PhysicalNames" << std::endl;
		file <<mesh_data.surfaceVector.size() << std::endl;
		for (int i = 0; i < mesh_data.surfaceVector.size(); i++){
			file << "2 " << i + 1 << " " << mesh_data.surfaceVector[i] << std::endl;	// i'm using in my example only physical surface, so dimension eqals 2
		}
		file << "$EndPhysicalNames" << std::endl;
	}

	void MeshExport::addNodes(std::fstream &file, const CMR &mesh_data) {
		file << "$Nodes" << std::endl << mesh_data.vertices.size() << std::endl;
		for (int i = 0; i < mesh_data.vertices.size(); i++){
			file << i + 1;
			for (const auto &vertex : mesh_data.vertices[i]) {
				file << " " << std::uppercase << std::scientific << vertex;
			}
			file << std::endl;
		}
		file << "$EndNodes" << std::endl;
	}

	void MeshExport::addElements(std::fstream &file, const CMR &mesh_data) {	// I skiped 'tags'
		file << "$Elements" << std::endl;
		int iter = 0, size = mesh_data.elementsT4.size() + mesh_data.elementsP6.size();
		file << size << std::endl;
		for (int i = 0; i < mesh_data.elementsT4.size(); i++){
			iter += 1;
			file << iter << " 4";	// tetrahydral, so it's '4'
			for (const VertexID &id: mesh_data.elementsT4[i]) {
				file << " " << id;
			}
			file << std::endl;
		}
		for (int i = 0; i < mesh_data.elementsP6.size(); i++){
			iter += 1;
			file << iter << " 6";	// prism, so it's '6'
			for (const VertexID &id : mesh_data.elementsP6[i]) {
				file << " " << id;
			}
			file << std::endl;
		}
		file << "$EndElements" << std::endl;
	}