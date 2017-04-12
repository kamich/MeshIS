//
// Created by Feonrr on 29/03/2017.
//

#ifndef ABAQUSEXPORTER_HELPERMETHODS_H
#define ABAQUSEXPORTER_HELPERMETHODS_H

#include <fstream>
#include <array>
#include <vector>

using std::array;
using std::fstream;
using std::vector;
namespace fileUtils
{
    template<class T, size_t size>

    void loadSingleElement(fstream & fstream1,const vector<array<T,size>> & elements ){
        for (int i = 0; i < elements.size(); i++) {
            fstream1 << (i + 1);
            for (const auto &elemt:elements[i])
                fstream1<< (", " + std::to_string(elemt));
            fstream1 << std::endl;
        }
    };
    template<class T, size_t size>
    void printInformation(std::fstream &file,const  array<T,size> & information) {
    for (const auto &line:information) {
        file << line << std::endl;
    };
}

}
#endif //ABAQUSEXPORTER_HELPERMETHODS_H
