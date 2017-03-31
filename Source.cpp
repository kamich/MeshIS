#include "Model/IO/Import/NastranMeshImporter.h"
#include <chrono>
#include <iostream>
using MeshIS::Model::Import::NastranMeshImporter;
using std::cout;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

int main() {
    const auto start = std::chrono::steady_clock::now();

    /* IMPORTANT - file's extension passed as string to Import method
     * AND importer's extension enum file type MUST match */

//    NastranMeshImporter importer(NastranFileType::BDF);
//    const auto mesh = importer.Import("/home/piotr/Pobrane/lil.bdf");

    NastranMeshImporter importer(NastranFileType::NAS);
    const auto mesh = importer.Import("/home/piotr/Pobrane/mesh.nas");
    const auto stop = std::chrono::steady_clock::now();
    const auto dura = duration_cast<milliseconds>(stop - start);

    cout<<"Succesfuly parsed file\n";
    cout<<"\tVertices:\t"<<mesh.vertices.size()<<'\n';
    cout<<"\tT3 elems:\t"<<mesh.elementsT3.size()<<'\n';
    cout<<"\tQ4 elems:\t"<<mesh.elementsQ4.size()<<'\n';
    cout<<"\tT4 elems:\t"<<mesh.elementsT4.size()<<'\n';
    cout<<"\tP6 elems:\t"<<mesh.elementsP6.size()<<'\n';
    cout<<"Time elapsed:"<<dura.count()<<"ms\n";
	return 0;
}