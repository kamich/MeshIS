//
// Created by Lukasz on 27.03.2017.
//

#ifndef MESHIS_ABAQUS_IMPORT_H
#define MESHIS_ABAQUS_IMPORT_H

#include "../MeshImporter.h"

class Abaqus_Importer : public MeshIS::Model::Import::MeshImporter{

    public: MeshIS::Model::Common::CMR Import(const string & absolute_file_path) override ;


};

#endif //MESHIS_ABAQUS_IMPORT_H
