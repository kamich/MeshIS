#include "PropertiesManager.h"
#include <iostream>

using namespace MeshIS::Model::Common;
using namespace MeshIS::Model::Properties;

void PropertiesManager::addSpecificHeat(CMR& cmr, ElementID id, PropertyValue value) {
	auto it = cmr.specificHeat.find(value);
	if (it != cmr.specificHeat.end())
		std::cout << "Override specific heat in element: " << id << std::endl;
	cmr.specificHeat.insert(std::pair<ElementID, PropertyValue>(id, value));
}
void PropertiesManager::addConductivity(CMR& cmr, ElementID id, PropertyValue value) {
	auto it = cmr.conductivity.find(value);
	if (it != cmr.conductivity.end())
		std::cout << "Override conductivity in element: " << id << std::endl;
	cmr.conductivity.insert(std::pair<ElementID, PropertyValue>(id, value));
}
void PropertiesManager::addDensity(CMR& cmr, ElementID id, PropertyValue value) {
	auto it = cmr.density.find(value);
	if (it != cmr.density.end())
		std::cout << "Override density in element: " << id << std::endl;
	cmr.density.insert(std::pair<ElementID, PropertyValue>(id, value));
}
void PropertiesManager::addTransferCoefficient(CMR& cmr, ElementID id, PropertyValue value) {
	auto it = cmr.heatTransferCoefficient.find(value);
	if (it != cmr.heatTransferCoefficient.end())
		std::cout << "Override heat transfer coefficient in element: " << id << std::endl;
	cmr.heatTransferCoefficient.insert(std::pair<ElementID, PropertyValue>(id, value));
}

