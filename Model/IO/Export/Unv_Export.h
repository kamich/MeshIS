
#include <string>
#include "../MeshExporter.h"
#include "../../../Common/CommonMeshRepresentation.h"

using MeshIS::Model::Common::CMR;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;

class Unv_Export : public MeshIS::Model::Export::MeshExporter {
public:
	void Export(const string& absolute_file_path, const CMR & mesh_data);

};