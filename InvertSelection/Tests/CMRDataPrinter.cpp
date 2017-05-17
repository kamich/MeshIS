// Created by maria

#include <iostream>
#include "CMRDataPrinter.h"


void CMRDataPrinter::print(CMR& cmr)
{
	printElements(cmr.elementsP6);
	printElements(cmr.elementsT4);
	printElements(cmr.elementsT3);
}


template<class T>
void CMRDataPrinter::printElements(T& elements)
{
	for (auto & element : elements)
	{
		for (auto x : element)
			std::cout << x << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}