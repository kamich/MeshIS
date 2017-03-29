#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "AbaqusExporter.h"

const std::vector<std::string> headers = {
        "*HEADING",
        "ABAQUS input deck",
        "**         Nodes",
        "*NODE, NSET=NALL"
};
const std::vector<std::string> footer = {
        "**All elements set",
        "*ELSET, GENERATE, ELSET=EALL",
        "1, 1942",
        "**         Node sets",
        "*NSET, NSET=wall-solid"
};
const std::vector<std::string> ending = {
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

void AbaqusExporter::Export(const string &absolute_file_path, const CMR &mesh_data) {
    std::fstream fs(absolute_file_path, std::ios::out);
    printInformation(fs, headers);
    printVertexes(fs, mesh_data);
    printElements(fs, mesh_data);
    printSets(fs,mesh_data);
    fs << std::endl;
    printInformation(fs, ending);
}

void AbaqusExporter::printElements(std::fstream &file, const CMR &mesh_data) {
    file << "**         Elements" << std::endl;
    printElementHeader(file, "C3D4");
    for (int i = 0; i < mesh_data.elementsT4.size(); i++) {
        file << (i + 1);
        for (const auto &elemt:mesh_data.elementsT4[i])
            file << (", " + std::to_string(elemt));
        file << std::endl;
    }
    if (mesh_data.elementsP6.size() > 0) {
        printElementHeader(file, "C3D6");
        for (int i = 0; i < mesh_data.elementsP6.size(); i++) {
            file << (i + 1);
            for (const auto &elemt:mesh_data.elementsP6[i])
                file << (", " + std::to_string(elemt));
            file << std::endl;
        }
    }
}

void AbaqusExporter::printVertexes(std::fstream &file, const CMR &mesh_data) {
    for (int i = 0; i < mesh_data.vertices.size(); i++) {
        file << (i + 1);
        for (const auto &vertex:mesh_data.vertices[i])
            file << "," << getSeparator(vertex) << std::uppercase << std::scientific << std::setprecision(9)
                 << fabs(vertex);
        file << std::endl;
    }
}

void AbaqusExporter::printSets(std::fstream &file, const CMR &mesh_data) {
    printInformation(file, footer);
    for (int i = 1; i < 222; i++) {//CMR doesn't contain Sets so setting as default 222
        file << i << ",";
        if (i % 8 == 0)file << std::endl;
    }
}
void AbaqusExporter::printSingleElementType(std::fstream &file,const CMR &mesh_data, std::string elemntType) {
        printElementHeader(file, elemntType);
        for (int i = 0; i < mesh_data.elementsT4.size(); i++) {
            file << (i + 1);
            for (const auto &elemt:mesh_data.elementsT4[i])
                file << (", " + std::to_string(elemt));
            file << std::endl;
        }
}

void AbaqusExporter::printInformation(std::fstream &file, vector<std::string> information) {
    for (const auto &line:information) {
        file << line << std::endl;
    }
}

void AbaqusExporter::printElementHeader(std::fstream &file, std::string elementType) {
    file<<"*ELEMENT, TYPE=" + elementType + ", ELSET=PID3"<<std::endl;
}