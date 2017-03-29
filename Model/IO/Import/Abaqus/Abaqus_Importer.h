//
// Created by Lukasz on 27.03.2017.
//

#ifndef MESHIS_ABAQUS_IMPORT_H
#define MESHIS_ABAQUS_IMPORT_H

#include "../MeshImporter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>



class Abaqus_Importer : public MeshIS::Model::Import::MeshImporter{


    public: MeshIS::Model::Common::CMR Import(const string & absolute_file_path) override ;

    private: std::fstream open_abaqus_file(const string & absolute_file_path);

    private: void Set_Nodes(std::fstream data_file, MeshIS::Model::Common::CMR &Abaqus_Elements);

    private: void Set_Elements(std::fstream data_file, MeshIS::Model::Common::CMR &Abaqus_Elements);

    private: void delete_point(string &line);

    private: double scientific_notation(string coordinates);

};

#endif //MESHIS_ABAQUS_IMPORT_H
