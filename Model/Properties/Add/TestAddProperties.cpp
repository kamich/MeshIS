#include "../../Common/CommonMeshRepresentation.h"
#include "PropertiesManager.h"
#include "../../../TestData/CMR_objects/CMR_TestObjects.h"
#include <iostream>

enum Type { CONDUCTIVITY = 1, DENSITY = 2, SPECIFIC_HEAT = 3, TRANSFER_COEFFICIENT = 4 };

void checkValue( CMR&, ElementID, PropertyValue, Type);



int main() {
	 ElementID id1 = 1, id2 = 2, id3 = 3, id4 = 4;
	 PropertyValue value1 = 20., value2 = 6.5, value3 = 7.867, value4 = 0.008;
	 MeshIS::Model::Common::CMR CMR = MeshIS::TestData::CMR::create_plate20x20();
	 MeshIS::Model::Properties::PropertiesManager Manager;

	Manager.addConductivity(CMR, id1, value1);
	Manager.addDensity(CMR, id2, value2);
	Manager.addSpecificHeat(CMR, id3,value3);
	Manager.addTransferCoefficient(CMR, id4, value4);
	
	//CHECK IF PASS
	checkValue(CMR, id1, value1, Type::CONDUCTIVITY);
	checkValue(CMR, id2, value2, Type::DENSITY);
	checkValue(CMR, id3, value3, Type::SPECIFIC_HEAT);
	checkValue(CMR, id4, value4, Type::TRANSFER_COEFFICIENT);

	//OVERRIDE 
	Manager.addConductivity(CMR, id1, value2);
	checkValue(CMR, id1, value2, Type::CONDUCTIVITY);
	
	//CHECK IF NOT PASS
	checkValue(CMR, id1, value4, Type::TRANSFER_COEFFICIENT);

	system("PAUSE");

}

void checkValue( CMR& cmr,  ElementID id, PropertyValue toCheck, Type type) {

	switch (type)
	{
	case CONDUCTIVITY:
		if (cmr.conductivity.find(id) != cmr.conductivity.end())
		{
			if (!toCheck == cmr.conductivity.find(id)->second)
				std::cerr << "Incorrect PROPERTY VALUE in CONDUCTIVITY" << std::endl;
		}
		else
			std::cerr << "Incorrect ELEMENTID in CONDUCTIVITY"<< std::endl;
		break;
	case DENSITY:
		if (cmr.density.find(id) != cmr.density.end())
		{
			if (!toCheck == cmr.density.find(id)->second)
				std::cerr << "Incorrect PROPERTY VALUE in DENSITY" << std::endl;
		}
		else
			std::cerr << "Incorrect ELEMENTID in DENSITY" << std::endl;
		break;
	case SPECIFIC_HEAT:
		if (cmr.specificHeat.find(id) != cmr.specificHeat.end())
		{
			if (!toCheck == cmr.specificHeat.find(id)->second)
				std::cerr << "Incorrect PROPERTY VALUE in SPECIFIC HEAT" << std::endl;
		}
		else
			std::cerr << "Incorrect ELEMENTID in SPECIFIC HEAT" << std::endl;
			break;
	case TRANSFER_COEFFICIENT:
		if (cmr.heatTransferCoefficient.find(id) != cmr.heatTransferCoefficient.end())
		{
			if (!toCheck == cmr.heatTransferCoefficient.find(id)->second)
				std::cerr << "Incorrect PROPERTY VALUE in TRANSFER COEFFICIENT" << std::endl;
		}
		else
			std::cerr << "Incorrect ELEMENTID in TRANSFER COEFFICIENT" << std::endl;
			break;
	default:
		std::cout << "Invalid type." << std::endl << std::endl;
		break;
	}

}