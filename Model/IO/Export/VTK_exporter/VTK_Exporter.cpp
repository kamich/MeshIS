#include "VTK_Exporter.h"

void VTK_Exporter::exportHeader()
{
	VTK_file << "# vtk DataFile Version 2.0\n";
	VTK_file << "MeshIS\n";
	VTK_file << "ASCII\n";
	VTK_file << "DATASET UNSTRUCTURED_GRID\n";
}

void VTK_Exporter::exportPoints(const CMR & mesh_data, int numOfPoints)
{
	VTK_file << "POINTS " << numOfPoints << " double\n";

	for (int i = 0; i < mesh_data.vertices.size(); i++) {
		VTK_file << mesh_data.vertices[i][0] << " "
			<< mesh_data.vertices[i][1] << " "
			<< mesh_data.vertices[i][2] << "\n";
	}

	VTK_file << "\n";
}

void VTK_Exporter::exportCells(const CMR & mesh_data, int numOfElements, int numOfEntries)
{
	VTK_file << "CELLS " << numOfElements << " " << numOfEntries << "\n";

	for (int i = 0; i < mesh_data.elementsT4.size(); i++) {
		VTK_file << "4 " << mesh_data.elementsT4[i][0] << " "
			<< mesh_data.elementsT4[i][1] << " "
			<< mesh_data.elementsT4[i][2] << " "
			<< mesh_data.elementsT4[i][3] << "\n";
	}
	for (int i = 0; i < mesh_data.elementsP6.size(); i++) {
		VTK_file << "6 " << mesh_data.elementsP6[i][0] << " "
			<< mesh_data.elementsP6[i][1] << " "
			<< mesh_data.elementsP6[i][2] << " "
			<< mesh_data.elementsP6[i][3] << " "
			<< mesh_data.elementsP6[i][4] << " "
			<< mesh_data.elementsP6[i][5] << "\n";
	}
	VTK_file << "\n";
}

void VTK_Exporter::exportCellTypes(const CMR & mesh_data, int numOfElements)
{
	VTK_file << "CELL_TYPES " << numOfElements << "\n";

	for (int i = 0; i < mesh_data.elementsT4.size(); i++) {
		VTK_file << "10\n";
	}
	for (int i = 0; i < mesh_data.elementsP6.size(); i++) {
		VTK_file << "13\n";
	}
}

void VTK_Exporter::Export(const string & absolute_file_path, const CMR & mesh_data)
{
	VTK_file.open(absolute_file_path, std::ios::out | std::ios::trunc);
	int i = 0;
	int numOfElements = mesh_data.elementsP6.size() + mesh_data.elementsT4.size();
	int numOfEntries = mesh_data.elementsP6.size() * 7 + mesh_data.elementsT4.size() * 5;
	if (VTK_file.good()) {
		exportHeader();
		exportPoints(mesh_data, mesh_data.vertices.size());
		exportCells(mesh_data, numOfElements, numOfEntries);
		exportCellTypes(mesh_data, numOfElements);	
	}
	VTK_file.close();
}
