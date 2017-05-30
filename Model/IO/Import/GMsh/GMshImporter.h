#pragma 
#ifndef MESHIS_GMSH_IMPORTER_H_
#define MESHIS_GMSH_IMPORTER_H_
#include "../MeshImporter.h"

namespace MeshIS
{
	namespace Model
	{
		namespace Import
		{
			class GMshMeshImporter : public MeshImporter
			{
			public:
				Common::CMR Import(const string & absolute_file_path) override;
			private:
				/// Variables
				Common::CMR cmr;
				int elements_amount;
				/// Functions
				void addElementToCMR(int, std::vector<int>&);
			};
			typedef  GMshMeshImporter GMshImporter;
		}//! end of namespace Import
	}//! end of namespace Model
}//! end of namespace MeshIS
#endif /* end of include guard: MESHIS_MESH_IMPORTER_H_ */