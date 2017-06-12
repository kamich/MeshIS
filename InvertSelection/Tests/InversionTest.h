// Created by maria

#ifndef INVERSIONTEST_H_
#define INVERSIONTEST_H_

#include <array>

#include "../../Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class InversionTest {

public:
	CMR invertAndPrintResults(CMR& all, CMR& selected);
	CMR invertDefaultDataAndPrintResults();

private:
	array<CMR, 2> generateDefaultTestData();
	
};

#endif /*INVERSIONTEST_H_*/
