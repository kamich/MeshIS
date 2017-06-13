#include "Multiselection.h"
template <class Temp>
CMR Multiselection::multiselection(CMR& cmr, vector<Temp> pom)
{
	for each ( Temp x in pom)
	{
		addSelect(x);
	}
	return cmr;
}
CMR Multiselection::addSelect(MeshIS::Model::Common::Vertex vertex, CMR& cmr)
{
	cmr.vertices.push_back(vertex);
	return cmr;
}
CMR Multiselection::addSelect(MeshIS::Model::Common::Element_T4 element, CMR& cmr)
{
	cmr.elementsT4.push_back(element);
	return cmr;
}
CMR Multiselection::addSelect(MeshIS::Model::Common::Element_P6 element, CMR& cmr)
{
	cmr.elementsP6.push_back(element);
	return cmr;
}