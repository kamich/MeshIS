#include "Ansys.h"
using namespace std;

MeshIS::Model::Common::CMR   Ansys::Import(const string & absolute_file_path)
{
    MeshIS::Model::Common::CMR;
    fstream file;
    file.open(absolute_file_path);
    skipFirstlineFile(file);
    setSizeNodeElement(file);
    tabNode=new Point3D[sizeNode];
    tabElement= new Point5D[sizeElement];
    int index=0,counter=getHowMany(file);
    importNodes(index,counter,tabNode,file);

    index=counter,counter=getHowMany(file);
    importNodes(index,counter,tabNode,file);

    index=0,counter=getHowMany(file);
    importElements(index,counter,tabElement,file);

    index=counter,counter=getHowMany(file);
    importElements(index,counter,tabElement,file);
    MeshIS::Model::Common::CMR result=savetoCmrObject();
    file.close();
    return result;
}
void Ansys::skipFirstlineFile(fstream &file) {
    string z;
    int i=0;
    do
    {
        getline(file,z);
        i++;
    }
    while(i<8);
}
int  Ansys::getHowMany(fstream &file) {
    string z;
    int i=0;
    do {
        file >> z;
        i++;
    }
    while(i!=3);
    int start = std::stoi(z, 0, 16);
    file>>z;
    int end= std::stoi(z, 0, 16);;
    int num=end-start+1;
    getline(file,z);
    return num;
}
void Ansys::importNodes(int index,int HowMany,Point3D* tab,fstream & file){
    string helpString;
    int counter=0;
    do
    {
       file>>tab[index].x;
       file>>tab[index].y;
        file>>tab[index].z;
        index++;
        counter++;
    } while (counter!=HowMany);
    getline(file,helpString);
    getline(file,helpString);
}
void Ansys::importElements(int index,int HowMany,Point5D*tab,fstream &file){
    string helpString;
    int counter=0;
    do
    {
        string hexvalue;
        file>>hexvalue;
        double decvalue=std::stoi(hexvalue, 0, 16);
        tab[index].a=decvalue;
        file>>hexvalue;
        decvalue=std::stoi(hexvalue, 0, 16);
        tab[index].b=decvalue;
        file>>hexvalue;
        decvalue=std::stoi(hexvalue, 0, 16);
        tab[index].c=decvalue;
        file>>hexvalue;
        decvalue=std::stoi(hexvalue, 0, 16);
        tab[index].d=decvalue;
        file>>hexvalue;
        decvalue=std::stoi(hexvalue, 0, 16);
        tab[index].e=decvalue;

        getline(file,helpString);
        index++;
    } while (counter!=HowMany);
    getline(file,helpString);
    getline(file,helpString);
}
void Ansys::setSizeNodeElement(fstream & file){
    sizeNode=getHowMany(file);
    sizeElement=getHowMany(file);
    getHowMany(file);
}
MeshIS::Model::Common::CMR Ansys::savetoCmrObject() {
 //funcion which save to object CMR;
    MeshIS::Model::Common::CMR result;
    for(int i=0;i<sizeNode;i++)
    {
        result.vertices.push_back({tabNode[i].x,tabNode[i].y,tabNode[i].z,});
    }
    for(int i=0;i<sizeElement;i++)
    {
        result.elementsP6.push_back({tabElement[i].a,tabElement[i].b,tabElement[i].c,tabElement[i].d,tabElement[i].e,0});
    }

    return result;
}


