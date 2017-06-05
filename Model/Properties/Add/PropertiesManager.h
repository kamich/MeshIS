#pragma once
#ifndef MESHIS_PROPERITIES_MANAGER_H_
#define MESHIS_PROPERITIES_MANAGER_H_

#include "../../Common/CommonMeshRepresentation.h"
using namespace MeshIS::Model::Common;
namespace MeshIS
{
	namespace Model
	{
		namespace Properties
		{
				class PropertiesManager
				{
				public:
					void addSpecificHeat(CMR&, ElementID, PropertyValue);
					void addConductivity(CMR&, ElementID, PropertyValue);
					void addDensity(CMR&, ElementID, PropertyValue);
					void addTransferCoefficient(CMR&, ElementID, PropertyValue);
				};
		}
	}
}

#endif