//
// Created by Kuba on 29.03.2017.
//
#ifndef VTU_XML_IMPORTER_H
#define VTU_XML_IMPORTER_H

#include "../../../Common/CommonMeshRepresentation.h"
#include "../MeshImporter.h"
#include "RapidXML/rapidxml.hpp"
#include "RapidXML/rapidxml_utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace MeshIS::Model::Common;
using namespace MeshIS::Model::Import;
using namespace rapidxml;
using namespace std;

class VTU_Import : public MeshImporter {

public:

    CMR Import(const string & ) override;


private:
    vector<int> types;
    vector<int> connectivities;


};


#endif