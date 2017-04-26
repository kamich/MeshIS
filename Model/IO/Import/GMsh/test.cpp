#include <iostream>
#include "GMshImporter.h"

int main()
{
	MeshIS::Model::Import::GMshImporter importer;
	MeshIS::Model::Common::CMR cmr = importer.Import("example1.msh");
	std::cin.get();

	//cout.precision(15);
	std::cout << cmr.vertices.size();
	for (int i = 0; i < cmr.vertices.size(); ++i)
	{
		std::cout << std::fixed << "Point " << i + 1 << ": " << cmr.vertices[i][0] << " " << cmr.vertices[i][1] << " " << cmr.vertices[i][2] << std::endl;
	}
	std::cin.get();
	
	std::cout << cmr.elementsT3.size();
	for (int i = 0; i < cmr.elementsT3.size(); ++i)
	{
		std::cout << std::fixed << "T3 " << i + 1 << ": " << cmr.elementsT3[i][0] << " " << cmr.elementsT3[i][1] << " " << cmr.elementsT3[i][2] << std::endl;
	}
	std::cin.get();

	std::cout << cmr.elementsT4.size();
	for (int i = 0; i < cmr.elementsT4.size(); ++i)
	{
		std::cout << std::fixed << "T4 " << i + 1 << ": " << cmr.elementsT4[i][0] << " " << cmr.elementsT4[i][1] << " " << cmr.elementsT4[i][2] << cmr.elementsT4[i][3] << std::endl;
	}
	std::cin.get();

	std::cout << cmr.elementsP6.size();
	for (int i = 0; i < cmr.elementsP6.size(); ++i)
	{
		std::cout << std::fixed << "P6 " << i + 1 << ": " << cmr.elementsP6[i][0] << " " << cmr.elementsP6[i][1] << " " << cmr.elementsP6[i][2]
			<< cmr.elementsP6[i][3] << " " << cmr.elementsP6[i][4] << " " << cmr.elementsP6[i][5] << std::endl;
	}
	std::cin.get();
}