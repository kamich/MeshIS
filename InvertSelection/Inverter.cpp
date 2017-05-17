// Created by maria

#include <iostream>
#include "Inverter.h"


CMR Inverter::invert(CMR& all, CMR& selected) {

	CMR result = all;

	// available element types: Element_T3, Element_T4, Element_T6;
	invertPart(selected.elementsP6, result.elementsP6);
	invertPart(selected.elementsT4, result.elementsT4);
	invertPart(selected.elementsT3, result.elementsT3);

	return result;
}


template<class T>
void Inverter::invertPart(T& selected, T& unselected)
{
	if (!selected.empty())
	{
		for (auto & actSelected : selected)
		{
			for (int i = 0; i < unselected.size(); i++)
			{
				if (actSelected == unselected[i])
				{
					for (int j = 0; j < unselected[i].size(); j++)
					{
						unselected[i].at(j) = -1;
					}
				}
			}
		}
	}
}