//
// Created by Kiełbasa Karol on 28.03.2017.
//

#ifndef CPP_MESHIMPORTER_H
#define CPP_MESHIMPORTER_H
#pragma #ifndef MESHIS_MESH_IMPORTER_H_
#define MESHIS_MESH_IMPORTER_H_

#include <string>
#include "../../Common/CommonMeshRepresentation.h"

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
              // virtual MeshIS:Model::Common::CommonMeshRepresentation Import(const string & absolute_file_path) = 0;
            };


        }//! end of namespace Import
    }//! end of namespace Model
}//! end of namespace MeshIS

#endif /* end of include guard: MESHIS_MESH_IMPORTER_H_ */

#endif //CPP_MESHIMPORTER_H
