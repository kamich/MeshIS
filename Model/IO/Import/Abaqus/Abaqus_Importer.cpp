//
// Created by Lukasz on 27.03.2017.
//

#include "Abaqus_Importer.h"




MeshIS::Model::Common::CMR Abaqus_Importer::Import(const string &absolute_file_path) {

    std::fstream data_file = open_abaqus_file(absolute_file_path);

    MeshIS::Model::Common::CMR Abaqus_Elements;

    Set_Nodes(data_file, Abaqus_Elements);

    Set_Elements(data_file, Abaqus_Elements);

    return Abaqus_Elements;

}

void Abaqus_Importer::Set_Nodes(std::fstream data_file, MeshIS::Model::Common::CMR &Abaqus_Elements) {

    string line;

    size_t positions_start;
    size_t positions_end;

    bool start_import = false;
    bool end_import = false;


    int node_id;

    string node_dimension [3];
    double node_dim[3];

    while(data_file.eof()){
        getline(data_file, line);

        positions_end = line.find("Elements");
        if(positions_end != string::npos){
            end_import = true;
        }

        if(start_import && !end_import){
            delete_point(line);
            std:: istringstream iss(line);
            iss >> node_id >> node_dimension[0] >>
                node_dimension[1]>> node_dimension[2];

            node_dim[0] = scientific_notation(node_dimension[0]);
            node_dim[1] = scientific_notation(node_dimension[1]);
            node_dim[2] = scientific_notation(node_dimension[2]);
            Abaqus_Elements.vertices.push_back({node_dim[0], node_dim[1], node_dim[2]});

        }

        positions_start = line.find("NODE");
        if(positions_start != string::npos){
            start_import = true;
        }



    }

}
void Abaqus_Importer::Set_Elements(std::fstream data_file, MeshIS::Model::Common::CMR &Abaqus_Elements) {

    string line;

    size_t positions_start;
    size_t positions_end;

    bool start_import = false;
    bool end_import = false;
    int element_id;
    int nodes_in_element [4];

    while(data_file.eof()){
        getline(data_file, line);

        positions_end = line.find("set");
        if(positions_end != string::npos){
            end_import = true;
        }

        if(start_import && !end_import){
            delete_point(line);

            std::istringstream iss(line);
            iss>>element_id>>nodes_in_element[0]>>nodes_in_element[1]
               >>nodes_in_element[2]>>nodes_in_element[3];

            Abaqus_Elements.elementsT4.push_back({nodes_in_element[0], nodes_in_element[1],
                                                  nodes_in_element[2], nodes_in_element[3]});




        }

        positions_start = line.find("ELEMENT");
        if(positions_start != string::npos){
            start_import = true;
        }


    }

}
double Abaqus_Importer::scientific_notation(string coordinates) {

    double value;
    int exponent;
    for(int i = 0; i < coordinates.length(); i++){
        if(coordinates[i] == 'E')
            coordinates[i] = ' ';
    }

    std::istringstream iss(coordinates);
    iss>>value>>exponent;

    return value * pow(10,exponent);
}
void Abaqus_Importer::delete_point(string &line) {
    for(int i =0; i< line.length(); i++){
        if(line[i] == ','){
            line[i] = ' ';
        }
    }
}
std::fstream Abaqus_Importer::open_abaqus_file(const string &absolute_file_path) {
    std::fstream data_file;
    data_file.open(absolute_file_path.c_str(), std::ios::in);

    if(data_file.good()){
        return data_file;
    } else{
        return nullptr;
    }

}
