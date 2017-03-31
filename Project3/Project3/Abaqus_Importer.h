#pragma once
//
// Created by Lukasz on 27.03.2017.
//

#ifndef MESHIS_ABAQUS_IMPORT_H
#define MESHIS_ABAQUS_IMPORT_H

#include "MeshImporter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>



class Abaqus_Importer : public MeshIS::Model::Import::MeshImporter {


public: MeshIS::Model::Common::CMR Import(const string & absolute_file_path) override;

private: std::fstream open_abaqus_file(const string & absolute_file_path);

private: void Set_Nodes(const string & absolute_file_path, MeshIS::Model::Common::CMR &Abaqus_Elements);

private: void Set_Elements(const string & absolute_file_path, MeshIS::Model::Common::CMR &Abaqus_Elements);

private: void set_T4_element(string &line, MeshIS::Model::Common::CMR &Abaqus_Elements);

private: void set_P6_element(string &line, MeshIS::Model::Common::CMR &Abaqus_Elements);

private: void delete_point(string &line);

private: double scientific_notation(string &coordinates);

private: bool recognize_element_T4(string line);



};

#endif //MESHIS_ABAQUS_IMPORT_H
