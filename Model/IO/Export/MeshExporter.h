#pragma 
#ifndef MESHIS_MESH_EXPORTER_H_
#define MESHIS_MESH_EXPORTER_H_

#include <string>
#include "CommonMeshRepresentation.h"

using std::string;

namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{

			/// Abstract class for all importing classes.
			class MeshExporter {
			public:
				virtual void   Export(const string& absolute_file_path, const Common::CMR& mesh_data) = 0;
			};


		}//! end of namespace Export
	}//! end of namespace Model
}//! end of namespace MeshIS

#endif /* end of include guard: MESHIS_MESH_EXPORTER_H_ */
