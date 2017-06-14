#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "ModFemExporter.h"





void ModFemExporter::Export(const string &absolute_file_path, const CMR &mesh_data) {
    if (mesh_data.vertices.size() > 0) {
        writeToFile(absolute_file_path, mesh_data);
    }
}

void ModFemExporter::writeToFile(const string &absolute_file_path, const CMR &mesh_data) {

    std::fstream fs(absolute_file_path, std::ios::out);
    printVertexes(fs, mesh_data);
    printEdges(fs, mesh_data);
    printFaces(fs,mesh_data);
    printElements(fs, mesh_data);
    fs << std::endl;

}

//because of interface, slight difference, and array incompatibility issues there are four similar funcitons

void ModFemExporter::printVertexes(std::fstream &file, const CMR &mesh_data) {
    int size=mesh_data.vertices.size();
    file<<size<<" "<<size+1<<std::endl;
    for (int i = 0; i < size; i++) {
        for (const auto &vertex:mesh_data.vertices[i])
            file <<vertex<<" ";
        file << std::endl;
    }
}
void ModFemExporter::printEdges(std::fstream &file, const CMR &mesh_data) {
    int size=mesh_data.edges.size();
    file<<size<<" "<<size+1<<std::endl;
    for (const auto & edges: mesh_data.edges) {
        file <<1;
        for (const auto &edge:edges)
            file <<edge<<" ";
        file << std::endl;
    }
}
void ModFemExporter::printFaces(std::fstream &file, const CMR &mesh_data) {
    int size=mesh_data.faces.size();
    file<<size<<" "<<size+1<<std::endl;
    for (int i = 0; i < size; i++) {
        file<<3<<" "<<11<<" "<<1<<" "<<0;
        file << std::endl;
        for (const auto &face:mesh_data.faces[i]) {
            file<<face<<" ";
        }
        file << std::endl;
    }
}

void ModFemExporter::printElements(std::fstream &file, const CMR &mesh_data) {
    int size=mesh_data.elemets.size();
    file<<size<<" "<<size+1<<std::endl;
    for (int i = 0; i < size; i++) {
        file<<mesh_data.elemets[i].size()<<" "<<0<<" "<<0<<" "<<0;
        file << std::endl;
        for (const auto &element:mesh_data.elemets[i]) {
            file<<element<<" ";
        }
        file << std::endl;
    }
}


