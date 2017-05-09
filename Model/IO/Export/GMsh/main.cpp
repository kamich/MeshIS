#include <iostream>
#include "ExportGMsh.h"

CMR cmr;

void loadExampleData() {
	cmr.surfaceVector = { "bottom", "righ", "top", "left" };
	// nodes values taken from Abaqus/test1/fluent.inp
	Vertex vertex1 = { -2.000000029E-01,1.212498173E-01,2.657158076E-01 };
	Vertex vertex2 = { -2.000000029E-01,9.395208954E-02,3.363113999E-01 };
	Vertex vertex3 = { -2.000000029E-01,1.533117890E-01,3.211169242E-01 };
	Vertex vertex4 = { -2.000000029E-01, 5.846185237E-02,2.813982963E-01 };
	Vertex vertex5 = { 2.000000029E-01,1.533117890E-01,3.211169242E-01 };
	Vertex vertex6 = { -2.000000029E-01, -5.846185237E-02,2.813982963E-01 };
	Vertex vertex7 = { -2.000000029E-01, 1.302296519E-01, 1.206205859E-01 };
	Vertex vertex8 = { -2.000000029E-01, 5.894345790E-02, 1.163512170E-01 };
	Vertex vertex9 = { -2.000000029E-01, 1.478815376E-01, 5.180113390E-02 };
	Vertex vertex10 = { -2.000000029E-01, 8.692438155E-02, 5.936373770E-02 };
	// my own combination of nodes
	Element_T4 elem_tet_1 = { 1,2,3,4 };
	Element_T4 elem_tet_2 = { 2,4,6,8 };
	Element_P6 elem_prism_1 = { 6,5,4,2,1,3 };
	Element_P6 elem_prism_2 = { 5,6,7,8,9,10 };

	cmr.vertices.push_back(vertex1);
	cmr.vertices.push_back(vertex2);
	cmr.vertices.push_back(vertex3);
	cmr.vertices.push_back(vertex4);
	cmr.vertices.push_back(vertex5);
	cmr.vertices.push_back(vertex6);
	cmr.vertices.push_back(vertex7);
	cmr.vertices.push_back(vertex8);
	cmr.vertices.push_back(vertex9);
	cmr.vertices.push_back(vertex10);

	cmr.elementsT4.push_back(elem_tet_1);
	cmr.elementsT4.push_back(elem_tet_2);
	cmr.elementsP6.push_back(elem_prism_1);
	cmr.elementsP6.push_back(elem_prism_2);
}

int main() {
	MeshExport meshExport;
	loadExampleData();
	meshExport.Export("test_export.msh", cmr);
	std::cout << "Done!" << std::endl << std::endl;

	return 0;
}