#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "ModFemExporter.h"


const std::array<std::string, 4> headers = {
        "*HEADING",
        "ABAQUS input deck",
        "**         Nodes",
        "*NODE, NSET=NALL"
};
const std::array<std::string, 5> footer = {
        "**All elements set",
        "*ELSET, GENERATE, ELSET=EALL",
        "1, 1942",
        "**         Node sets",
        "*NSET, NSET=wall-solid"
};
const std::array<std::string, 13> ending = {
        "**         Element sets",
        "**         Element properties",
        "*SOLID SECTION, ELSET=PID3, MATERIAL=MID3",
        "**         Material properties",
        "*MATERIAL, NAME=MID3",
        "*ELASTIC, TYPE=ISOTROPIC",
        "1., 0.,",
        "**         Contact pairs and Co-simulation",
        "**         Steps",
        "*STEP",
        "*STATIC",
        "*BOUNDARY, OP=NEW",
        "*END STEP"
};

const std::string elementHeader = "**         Elements";



void ModFemExporter::Export(const string &absolute_file_path, const CMR &mesh_data) {
    if (mesh_data.vertices.size() > 0) {
        writeToFile(absolute_file_path, mesh_data);
    }
}

void ModFemExporter::writeToFile(const string &absolute_file_path, const CMR &mesh_data) {

    std::fstream fs(absolute_file_path, std::ios::out);
    //fileUtils::printInformation(fs, headers);
    printVertexes(fs, mesh_data);
    printEdges(fs, mesh_data);
    printFaces(fs,mesh_data);
    printElements(fs, mesh_data);

    fs << std::endl;
    //fileUtils::printInformation(fs, ending);
}

/*void ModFemExporter::printElements(std::fstream &file, const CMR &mesh_data) {
    std::string tetraHedron="C3D4";
    std::string prism="C3D6";
    file << "**         Elements" << std::endl;
    printElementHeader(file, tetraHedron);
    fileUtils::loadSingleElement(file, mesh_data.elementsT4);
    if (mesh_data.elementsP6.size() > 0) {
        printElementHeader(file,prism);
        fileUtils::loadSingleElement(file, mesh_data.elementsT4);
    }
}*/

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
    for (int i = 0; i < size; i++) {
        file <<1;
        for (const auto &edges:mesh_data.edges[i])
            file <<edges<<" ";
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
    int size=mesh_data.faces.size();
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


void ModFemExporter::printSets(std::fstream &file, const CMR &mesh_data) {
    fileUtils::printInformation(file, footer);
    for (int i = 1; i < 222; i++) {//CMR doesn't contain Sets so setting as default 222
        file << i << ",";
        if (i % 8 == 0)file << std::endl;
    }
}

void ModFemExporter::printElementHeader(std::fstream &file, std::string elementType) {
    file << "*ELEMENT, TYPE=" + elementType + ", ELSET=PID3" << std::endl;
}