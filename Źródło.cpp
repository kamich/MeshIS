#include <iostream>
#include "Su2MeshImporter.h"

using namespace std;
using namespace MeshIS::Model::Import;
using namespace MeshIS::Model::Common;

int main() {



	
	SU2LImporter importer;

	CMR cmr = importer.Import("example1.su2");
	cout << "Liczba punktow " << cmr.vertices.size() << endl;
	cout << "Liczba elementow " << cmr.elementsP6.size() << endl;
	
	system("PAUSE");
}