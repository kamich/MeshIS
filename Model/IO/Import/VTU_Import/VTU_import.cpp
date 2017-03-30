//
// Created by Kuba on 29.03.2017.
//

#include "VTU_import.h"

CMR VTU_Import::Import(const string & path) {

    CMR cmr;
    std::fstream file;
    file.open(path.c_str(), std::ios::in | std::ios::out);
    vector<char> buff((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    buff.push_back('\0');
    xml_document<> doc;
    doc.parse<0>(&buff[0]);


    xml_node<> * root_node= doc.first_node("VTKFile");
    root_node = root_node->first_node("UnstructuredGrid");
    root_node = root_node->first_node("Piece");

    double points_count = atof(root_node->first_attribute("NumberOfPoints")->value());
    double cell_count = atof(root_node->first_attribute("NumberOfCells")->value());

    xml_node<> * points_node;
    points_node = root_node->first_node("Points");
    points_node = points_node->first_node("DataArray");

    xml_node<> * cells_node;
    cells_node = root_node->first_node("Cells");
    cells_node = cells_node->first_node("DataArray");

    stringstream pointStream(points_node->value());

    for (int i = 0; i < points_count; i++)
    {
        float x,y,z;
        pointStream >> x;
        pointStream >> y;
        pointStream >> z;
        cmr.vertices.push_back({x,y,z});
    }

    //stringstream pointStream2(cells_node->value());

   // for (int i = 0; i < cell_count; i++)
    //{

    //}


}





