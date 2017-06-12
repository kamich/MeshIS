// Created by maria

#ifndef CMRDATADPINTER_H_
#define CMRDATADPINTER_H_

#include "../../Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class CMRDataPrinter {

public:
	void print(CMR& cmr);

private:
	template<class T>
	void printElements(T& elements);

};

#endif /*CMRDATADPINTER_H_*/