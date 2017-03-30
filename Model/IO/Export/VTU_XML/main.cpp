#include "ParaviewVTKXMLexporter.h"
#include "../../../Common/CommonMeshRepresentation.h"
#include <iostream>

	/*======================================
	FILE JUST FOR TEST EXPORT TO XML .VTU)
        ======================================*/

using MeshIS::Model::Element_P6;
using MeshIS::Model::Element_T4;
int main()
{
	MeshIS::Model::CMR CMR;
	MeshIS::Model::Export::ParaviewVTKXMLExporter Exporter;
	std::vector<Element_T4> connectivity;
	std::string path = "test1.vtu";

	for (double i = 0; i < 99; i++)
	{
		CMR.vertices.push_back({ i,i,i });
	}
	for ( int j = 100, k = 1000; j < 1000; k++, j++)
	{
		CMR.elementsT4.push_back({ j,j,j,j });
		connectivity.push_back({ k,k,k,k });
	}
	
	Exporter.setConnectivitiesT4(connectivity);
	Exporter.Export(path, CMR);
}
