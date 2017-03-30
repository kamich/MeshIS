//
// Created by Kuba on 29.03.2017.
//

#include "../VTU_import.h"

class Test{

public:
    void import(){

        VTU_Import VTU_imporer;
        MeshImporter& importer=VTU_imporer;
        CMR data=importer.Import("C:\\Users\\Kuba\\CLionProjects\\MeshIS\\Model\\IO\\Import\\VTU_Import\\Test\\test1.vtu");

    }
};

int main(){

    Test test;
    test.import();

}

