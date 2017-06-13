#include "CommonMeshRepresentation.h"
using MeshIS::Model::Common::CMR;

class Multiselection
{
	
	CMR addSelect(MeshIS::Model::Common::Vertex,CMR&);
	CMR addSelect(MeshIS::Model::Common::Element_T4,CMR&);
	CMR addSelect(MeshIS::Model::Common::Element_P6,CMR&);
public:
	template <class Temp>
	CMR multiselection( CMR&,vector<Temp>);

};