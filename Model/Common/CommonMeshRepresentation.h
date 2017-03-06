#pragma once
/**
 * @file Common mesh representation class.
 * Used for interfacing different components of code and passing informations about meshes.
 * @author Kazimierz Michalik
 */


#include <vector>
#include <array>

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
    typedef array<double,3> Vertex;
    typedef int             VertexID;

    // Element is defined as 4 vertices:
    // no need for such simple class either.
    typedef array<VertexID,4> Element;
    typedef int               ElementID;

    class CommonMeshRepresentation
    {
        public:
        // Since all fields are well-defined,
        // all constructors and

        vector<Vertex>      vertices;
        vector<Element>     elements;

    };

    typedef CommonMeshRepresentation CMR; //< just for convenience to void typing this long name

} //! end of namespace Common
} //! end of namespace Model
} //! end of namespace MeshIS
