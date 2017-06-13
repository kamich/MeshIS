#include "../../Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class NeighbourSelections
{
public:
	template<class T>
	vector<T> * neighbourSelectionsSimple(CMR & all, T& element);
	template<class T>
	vector<T> * neighbourSelectionsMulti(CMR & all, vector<T> elements);

};

