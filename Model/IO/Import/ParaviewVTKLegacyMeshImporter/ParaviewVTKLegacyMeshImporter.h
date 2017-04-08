#ifndef MESHIS_PARAVIEW_VTK_LEGACY_IMPORTER_H_
#define MESHIS_PARAVIEW_VTK_LEGACY_IMPORTER_H_
#include "MeshImporter.h"

namespace MeshIS
{
namespace Model
{
namespace Import
{

class ParaviewVTKLegacyMeshImporter : public MeshImporter
{
public:
	Common::CMR Import(const string & absolute_file_path) override;

private:
	Common::CMR cmr;
	std::vector<std::vector<int>> temp_elements;
	int elements_amount;

	void addElementToCMR(int, std::vector<int>&);

	enum ParaviewElementTypes // not using enum class to avoid strong typing and need of casting
	{
		Triangular = 5,
		Quadrilateral = 9,
		Prismatic = 13
	};
};

typedef  ParaviewVTKLegacyMeshImporter PVTKLImporter;

}
}
}

#endif