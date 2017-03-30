//
// Created by Kuba on 29.03.2017.
//

#include "VTU_import.h"


//TODO program works with tetragonal elements used in test files, which were not included in base version of CMR, i have added suitable variable on my local branch
/**
 *
 * test program demands to provide the absolute path to imported file
 * the issue of compression wasn't developed
 *
 * **/


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

    int points_count = atof(root_node->first_attribute("NumberOfPoints")->value());
    int cell_count = atof(root_node->first_attribute("NumberOfCells")->value());

    xml_node<> * points_node;
    points_node = root_node->first_node("Points");
    points_node = points_node->first_node("DataArray");

    xml_node<> * cells_node;
    cells_node = root_node->first_node("Cells");
   // cells_node = cells_node->first_node("DataArray");

    stringstream pointStream(points_node->value());

    for (int i = 0; i < points_count; i++)
    {
        float x,y,z;
        pointStream >> x;
        pointStream >> y;
        pointStream >> z;
        cmr.vertices.push_back({x,y,z});
    }

    int count=0;
    for (xml_node<> * data = cells_node->first_node("DataArray"); data; data = data->next_sibling()){

        string name= data->first_attribute("Name")->value();
        if (name=="types") {
            string type=data->first_attribute("RangeMin")->value();
            if(type=="10") count=4;
            else if(type=="5") count=3;
            else if(type=="12") count=6;
            break;
        }
    }

    if(count!=0) {
        for (xml_node<> *data = cells_node->first_node("DataArray"); data; data = data->next_sibling()) {

            string name = data->first_attribute("Name")->value();
            if (name == "connectivity") {
                getVerticesIDs(count,data->value(),cell_count,&cmr);

            }
        }
    }

    return cmr;


}

void VTU_Import::getVerticesIDs(int range,string data,int cell_count,CMR *cmr){

    stringstream cellStream(data);
    for(int i=0;i<cell_count;i++){
        if(range==3){
            double id1,id2,id3;
            cellStream >> id1;
            cellStream >> id2;
            cellStream >> id3;
            Element_T3 el;
            el[0]=(VertexID)id1;
            el[1]=(VertexID)id2;
            el[2]=(VertexID)id3;
            cmr->elementsT3.push_back(el);
        }
        else if(range==4){
            double id1,id2,id3,id4;
            cellStream >> id1;
            cellStream >> id2;
            cellStream >> id3;
            cellStream >> id4;
            Element_T4 el;
            el[0]=(VertexID)id1;
            el[1]=(VertexID)id2;
            el[2]=(VertexID)id3;
            el[3]=(VertexID)id4;
            cmr->elementsT4.push_back(el);
        }
        else if(range==6){
            double id1,id2,id3,id4,id5,id6;
            cellStream >> id1;
            cellStream >> id2;
            cellStream >> id3;
            cellStream >> id4;
            cellStream >> id5;
            cellStream >> id6;
            Element_P6 el;
            el[0]=(VertexID)id1;
            el[1]=(VertexID)id2;
            el[2]=(VertexID)id3;
            el[3]=(VertexID)id4;
            el[4]=(VertexID)id5;
            el[5]=(VertexID)id6;
            cmr->elementsP6.push_back(el);
        }
    }
}





