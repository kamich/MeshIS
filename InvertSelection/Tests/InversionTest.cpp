// Created by maria

#include <iostream>
#include "InversionTest.h"
#include "CMRDataPrinter.h"
#include "../Inverter.h"

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_P6;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_T3;
using namespace std;

CMR InversionTest::invertAndPrintResults(CMR& all, CMR& selected)
{
	CMRDataPrinter printer;
	printer.print(selected);

	std::cout << "inverting... \t" << std::endl;
	Inverter inverter;
	CMR result = inverter.invert(all, selected);

	printer.print(result);

	return result;
}

CMR InversionTest::invertDefaultDataAndPrintResults()
{
	array<CMR, 2> data = generateDefaultTestData();

	CMRDataPrinter printer;
	printer.print(data.at(1));

	std::cout << "inverting... \t" << std::endl;
	Inverter inverter;
	CMR result = inverter.invert(data.at(0), data.at(1));

	printer.print(result);

	return result;
}


array<CMR, 2> InversionTest::generateDefaultTestData()
{
	CMR all;
	CMR selected;

	Element_P6 e6;
	Element_T4 e4;
	Element_T3 e3;

	for (int i = 0; i < 10; i++)
	{
		e6 = { i,6,6,6,6,6 };
		all.elementsP6.push_back(e6);

		e4 = { i,4,4,4 };
		all.elementsT4.push_back(e4);
		
		e3 = { i,3,3 };
		all.elementsT3.push_back(e3);
	}

	for (int i = 0; i < 10; i ++)
	{
		if (i % 2 == 0)
		{
			e6 = { i,6,6,6,6,6 };
			e4 = { i,4,4,4 };
			e3 = { i,3,3 };
		}
		else
		{
			e6 = { -1,-1,-1,-1,-1,-1 };
			e4 = { -1,-1,-1,-1 };
			e3 = { -1,-1,-1 };
		}
		selected.elementsP6.push_back(e6);
		selected.elementsT4.push_back(e4);
		selected.elementsT3.push_back(e3);
	}
	
	array<CMR, 2> data = {all, selected};
	return data;
}

