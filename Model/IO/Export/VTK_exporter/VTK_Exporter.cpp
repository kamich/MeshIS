#include "VTK_Exporter.h"

void VTK_Exporter::Export(const string & absolute_file_path, const CMR & mesh_data)
{
	VTK_file.open(absolute_file_path, std::ios::out | std::ios::trunc);
	int i = 0;
	if (VTK_file.good()) {
		VTK_file << "# vtk DataFile Version 2.0\n";
		VTK_file << "MeshIS\n";
		VTK_file << "ASCII\n";
		VTK_file << "DATASET UNSTRUCTURED_GRID\n";
		VTK_file << "POINTS " << mesh_data.vertices.size() << " double\n";
		for (i = 0; i < mesh_data.vertices.size(); i++) {
			VTK_file << mesh_data.vertices[i][0] << " "
				<< mesh_data.vertices[i][1] << " "
				<< mesh_data.vertices[i][2] << "\n";
		}
		VTK_file << "\n";
		VTK_file << "CELLS " << mesh_data.elementsP6.size() + mesh_data.elementsT4.size()
			<< " " << mesh_data.elementsP6.size() * 7 + mesh_data.elementsT4.size() * 5 << "\n";
		for (i = 0; i < mesh_data.elementsT4.size(); i++) {
			VTK_file << "4 " << mesh_data.elementsT4[i][0] << " "
				<< mesh_data.elementsT4[i][1] << " "
				<< mesh_data.elementsT4[i][2] << " "
				<< mesh_data.elementsT4[i][3] << "\n";
		}
		for (i = 0; i < mesh_data.elementsP6.size(); i++) {
			VTK_file << "6 " << mesh_data.elementsP6[i][0] << " "
				<< mesh_data.elementsP6[i][1] << " "
				<< mesh_data.elementsP6[i][2] << " "
				<< mesh_data.elementsP6[i][3] << " "
				<< mesh_data.elementsP6[i][4] << " "
				<< mesh_data.elementsP6[i][5] << "\n";
		}
		VTK_file << "\n";
		VTK_file << "CELL_TYPES " << mesh_data.elementsP6.size() + mesh_data.elementsT4.size() << "\n";
		for (i = 0; i < mesh_data.elementsT4.size(); i++) {
			VTK_file << "10\n";
		}
		for (i = 0; i < mesh_data.elementsP6.size(); i++) {
			VTK_file << "13\n";
		}

		VTK_file.close();
	}
}
