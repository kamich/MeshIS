// Created by maria

#ifndef INVERTER_H_
#define INVERTER_H_

#include "../Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class Inverter {

public:	
	CMR invert(CMR& all, CMR& selected);

private:
	static const int notSelected = -1;

	template<class T>
	void invertPart(T& selected, T& unselected);
	
};

#endif /*INVERTER_H_*/