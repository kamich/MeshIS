#pragma 
#ifndef MESHIS_ModFEM_MESH_REPRESENTATION_H_
#define MESHIS__ModFEM_MESH_REPRESENTATION_H_


#include <vector>
#include <array>
#include "CommonMeshRepresentation.h"
using std::vector;
using std::array;

namespace MeshIS
{
namespace Model
{
namespace Common
{
    // Vertex is defined as 3 floating points coordinates in space:
    // no need for such simple class.

	typedef array<VertexID,2> 	Edge;
	typedef int 				EdgeID;
	
	typedef array<EdgeID,3>	 	TriangularFace;
	typedef array<EdgeID,4>	 	QuadrilateralFace;
	
	typedef int					FaceID;
	
    typedef int               	ElementID;
    typedef array<FaceID,5> 	Element_F5;	//< Prismatic elements with 5 faces.

	typedef int               	ElementID;
	typedef array<FaceID, 4> 	Element_F4;	

    class ModFemMeshRepresentation : public CMR
    {
        public:
        // Since all fields are well-defined (no pointers, no strange classes),
        // all default constructors etc. will be ok.

		vector<Edge>	 			edges;
		vector<TriangularFace> 		triangularfaces;
		vector<QuadrilateralFace> 	quadrilateralfaces;
		vector<Element_F5>     		elementsF5; //elements with 5 faces
		vector<Element_F4>     		elementsF4;
    };

    typedef ModFemMeshRepresentation ModFEMCMR; //< Just for convenience, to avoid typing this long name.

} //! end of namespace Common
} //! end of namespace Model
} //! end of namespace MeshIS


#endif /* end of include guard: MESHIS_COMMON_MESH_REPRESENTATION_H_ */