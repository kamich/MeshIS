#pragma 
#ifndef MESHIS_ModFEM_IMPORTER_H_
#define MESHIS_ModFEM_IMPORTER_H_

#include "MeshImporter.h"
#include "../../Common/ModFemMeshRepresentation.h"


namespace MeshIS
{
namespace Model
{
namespace Import
{

class ModFEMMeshImporter : public MeshImporter
{
public:	
	Common::CMR Import(const string & absolute_file_path) override;
private:
	Common::CMR cmr;
	Common::ModFEMCMR modfemcmr;
	std::vector<std::vector<int>> temp_elements;
	int elements_amount;
	int vertex_amount;

	void addElementToCMR(int, std::vector<int>&);
};

}
}
}

#endif