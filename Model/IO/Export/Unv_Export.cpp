#include <iostream>
#include <fstream>
#include <string>
#include "../MeshExporter.h"
#include "../../../Common/CommonMeshRepresentation.h"
 

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T3;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;

void MeshExport::Export(const string& absolute_file_path, const CMR & mesh_data) {
	std::fstream file;
	file.open(absolute_file_path, std::ios::out);
	if (file.good()) {



		int elementId = 1;
		int typElementu = 44  //Plane Stress Linear Quadrilateral
			int numberOfNodesInElement = 4;
		for (auto element = cmr.elementsT4.begin(); element != cmr.elementsT4.end(); ++element)
		{
			string record1 = "\t " + elementId + "\t" + typElementu + "\t" + 0 + "\t" + 0 + "\t" + 0 + "\t" + numberOfNodesInElement;

			string record2 = "";
			for (int i = 0; i < numberOfNodesInElement; i++)
			{
				record2 += element[i];
				record2 += "\t"
			}
			file.writeline(record1);
			file << std::endl;
			file.writeline(record2)
				file << std::endl;
				elementId++;
		}


		int elementId = 1;
		int typElementu = 74  // Membrane Linear Triangle
			int numberOfNodesInElement = 3;
		for (auto element = cmr.elementsT3.begin(); element != cmr.elementsT3.end(); ++element)
		{
			string record1 = "\t " + elementId + "\t" + typElementu + "\t" + 0 + "\t" + 0 + "\t" + 0 + "\t" + numberOfNodesInElement;

			string record2 = "";
			for (int i = 0; i < numberOfNodesInElement; i++)
			{
				record2 += element[i];
				record2 += "\t"
			}
			file.writeline(record1);
			file << std::endl;
			file.writeline(record2)
				file << std::endl;
			elementId++;
		}

		
	}
}



	