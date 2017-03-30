//
// Created by Kuba on 29.03.2017.
//

#include <ctime>
#include <chrono>
#include "../VTU_import.h"


class Test{

public:
    void import(){


        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();

        VTU_Import VTU_imporer;
        MeshImporter& importer=VTU_imporer;
        CMR data=importer.Import("C:\\Users\\Kuba\\CLionProjects\\MeshIS\\Model\\IO\\Import\\VTU_Import\\Test\\test_1.vtu");

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "\nelapsed time: " << elapsed_seconds.count() << "s\n";

    }
};

int main(){

    Test test;

    test.import();

    delete &test;

}

