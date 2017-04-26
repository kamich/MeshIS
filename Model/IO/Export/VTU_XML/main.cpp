#include "ParaviewVTKXMLexporter.h"
#include "../../../Common/CommonMeshRepresentation.h"
#include "../../../../TestData/CMR_objects/CMR_TestObjects.h"
#include <iostream>


int main()
{
	MeshIS::Model::CMR CMR = MeshIS::TestData::CMR::create_plate20x20();
	MeshIS::Model::Export::ParaviewVTKXMLExporter Exporter;
	std::string path = "test1.vtu";
	Exporter.Export(path, CMR);
}
