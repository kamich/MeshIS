#pragma #ifndef MESHIS_MESH_IMPORTER_H_
#define MESHIS_MESH_IMPORTER_H_

#include <string>
#include "CommonMeshRepresentation.h"

using std::string;

namespace MeshIS
{
namespace Model
{
namespace Import
{

  /// Abstract class for all importing classes.
  class MeshImporter {
    public:
      CMR   Import(const string & absolute_file_path) = 0;
  };


}//! end of namespace Import
}//! end of namespace Model
}//! end of namespace MeshIS

#endif /* end of include guard: MESHIS_MESH_IMPORTER_H_ */
