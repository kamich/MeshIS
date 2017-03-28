//
// Created by Feonrr on 21/03/2017.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "AbaqusExporter.h"

std::vector<std::string> headers = {
        "*HEADING",
        "ABAQUS input deck",
        "**         Nodes",
        "*NODE, NSET=NALL"
};
std::vector<std::string> elemntHeaders = {
        "**         Elements",
        "*ELEMENT, TYPE=C3D4, ELSET=PID3"
};
std::vector<std::string> footer = {
        "**All elements set",
        "*ELSET, GENERATE, ELSET=EALL",
        "1, 1942",
        "**         Node sets",
        "*NSET, NSET=wall-solid"
};
std::vector<std::string> ending = {
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

void AbaqusExporter::Export(const string &absolute_file_path, const CMR &mesh_data) {
    std::fstream fs;
    fs.open(absolute_file_path, std::ios::out);
    printInformation(fs, headers);
    printVertexes(fs, mesh_data.vertices);
    printInformation(fs, elemntHeaders);
    printElements(fs, mesh_data.elementsT4);
    printInformation(fs, footer);

    for (int i = 1; i < 222; i++) {
        fs << i << ",";
        if (i % 8 == 0)fs << std::endl;
    }
    fs << std::endl;
    printInformation(fs, ending);

    fs.close();
}

void writeDataToFile() {

}

void AbaqusExporter::printElements(std::fstream &file, vector<Element_T4> elements) {
    for (int i = 0; i < elements.size(); i++) {
        file << (i + 1);
        for (auto elemt:elements[i])
            file << (", " + std::to_string(elemt));
        file << std::endl;
    }
}

void AbaqusExporter::printVertexes(std::fstream &file, vector<Vertex> vertexes) {
    for (int i = 0; i < vertexes.size(); i++) {
        file << (i + 1);
        for (auto vertex:vertexes[i])
            file << "," << getSeparator(vertex) << std::uppercase << std::scientific << std::setprecision(9)
                 << fabs(vertex);
        file << std::endl;
    }
}

void AbaqusExporter::printInformation(std::fstream &file, vector<std::string> information) {
    for (auto line:information) {
        file << line << std::endl;
    }
}



