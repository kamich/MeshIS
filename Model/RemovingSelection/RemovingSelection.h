#include "../../Model/Common/CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class RemovingSelection
{
public:
	CMR removeSelection(CMR& all);
private:
	template<class T>
	void remove(T& elements);
};

