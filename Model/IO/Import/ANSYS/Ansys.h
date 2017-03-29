
#ifndef MESHIS_MASTER_ANSYS_H
#define MESHIS_MASTER_ANSYS_H

#include <iostream>
#include <fstream>
#include "../MeshImporter.h"
using  namespace std;
class Ansys :public MeshIS::Model::Import::MeshImporter {
private:
    int sizeNode,sizeElement;
    Point3D *tabNode;
    Point5D *tabElement;
public:
    MeshIS::Model::Common::CMR Import(const string &absolute_file_path) override;
    void skipFirstlineFile(fstream &);
    int  getHowMany(fstream &);
    void importNodes(int,int,Point3D*,fstream &);
    void importElements(int,int,Point5D*,fstream &);
    void setSizeNodeElement(fstream &);
    MeshIS::Model::Common::CMR savetoCmrObject();

};
class Point3D
{
public:
    double x,y,z;
};
class Point5D
{
public:
    int a,b,c,d,e;
};
#endif //MESHIS_MASTER_ANSYS_H
