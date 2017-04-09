#ifndef MESHIS_ModFEM_IMPORTER_H_
#define MESHIS_ModFEM_IMPORTER_H_

#include "MeshImporter.h"
#include "../../Common/ModFemMeshRepresentation.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include "boost/variant.hpp"
#include <set>

namespace MeshIS
{
namespace Model
{
namespace Import
{
	using Common::Vertex;
	using Common::Edge;
	using Common::TriangularFace;
	using Common::QuadrilateralFace;
	using Common::Element_F5;
	using Common::Element_F4;
	using Common::Element_P6;
	using Common::Element_T4;

class ModFEMMeshImporter : public MeshImporter
{
public:	
	Common::CMR Import(const string & absolute_file_path) override;
private:
	Common::CMR cmr;
	Common::ModFEMCMR modfemcmr;
	int elements_amount;
	int vertex_amount;
	int face_amount;
	int edges_amount;
	int type;
	vector <boost::variant<TriangularFace, QuadrilateralFace>> faces;
	array<float,3>_points;
	array<int, 6>_vertices;
	array<int,4>_edges;
	array<int,5>_faces;

	void translateF5toP6(std::vector<MeshIS::Model::Common::Element_F5>&);
	void translateF4toT4(std::vector<MeshIS::Model::Common::Element_F4>&);
	void importPoints(std::fstream & );
	void importEdges(std::fstream &);
	void importFaces(std::fstream &);
	void importElements(std::fstream &);


};

}
}
}

#endif
