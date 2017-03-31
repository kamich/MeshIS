
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
      virtual CMR   Import(const string & absolute_file_path) = 0;
  };


}//! end of namespace Import
}//! end of namespace Model
}//! end of namespace MeshIS


