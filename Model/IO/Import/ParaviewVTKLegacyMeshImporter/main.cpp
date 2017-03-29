#include <iostream>
#include "ParaviewVTKLegacyMeshImporter.h"

using namespace std;
using namespace MeshIS::Model::Import;
using namespace MeshIS::Model::Common;


int main()
{

	PVTKLImporter importer;

	CMR cmr = importer.Import("example1_ascii.vtk");

	/*std::cout << cmr.vertices.size();
	for (int i = 0; i < cmr.vertices.size(); ++i)
	{
		std::cout << "Point " << i << ": " << cmr.vertices[i][0] << " " << cmr.vertices[i][1] << " " << cmr.vertices[i][2] << std::endl;
	}
	std::cin.get();*/
	std::cout << cmr.elementsP6.size();
	for (int i = 0; i < cmr.elementsP6.size(); ++i)
	{
		std::cout << "P6 " << i << ": " << cmr.elementsP6[i][0] << " " << cmr.elementsP6[i][1] << " " << cmr.elementsP6[i][2]
			<< cmr.elementsP6[i][3] << " " << cmr.elementsP6[i][4] << " " << cmr.elementsP6[i][5] << std::endl;
	}
	std::cin.get();

	

}
