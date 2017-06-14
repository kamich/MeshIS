#pragma once
#include "../../Common/CommonMeshRepresentation.h"
#include<vector>
using MeshIS::Model::Common::CMR;

class DirectElementSelection {
public:
	template<class T>
	std::vector<T> directSelect(CMR & data, std::vector<int> verticesID);
};
