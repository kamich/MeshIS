#ifndef VTU_XML_IMPORTER_H
#define VTU_XML_IMPORTER_H

#include "../../../Common/CommonMeshRepresentation.h"
#include "../MeshImporter.h"
#include "rapidXML/rapidxml.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace MeshIS::Model::Common;
using namespace MeshIS::Model::Import;
using namespace rapidxml;
using namespace std;

class Vtu_xml_importer : public MeshImporter {

	public: 

		CMR Import(const string & absolute_file_path) override;
		
	private:
		vector<int> types;
		vector<int> connectivities;

		void setConnectiivities(CMR *VtuCMR);
		void fillConnectivitiesVector(string data);
		void fillTypeVector(string data);
		void fillMesh(CMR *vtuCMR);
};


#endif
