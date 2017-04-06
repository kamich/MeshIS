#ifndef NASTRAN_MESH_IMPORTER_H_
#define NASTRAN_MESH_IMPORTER_H_

#include <memory>
#include "BdfParser.h"
#include "NasParser.h"
#include "MeshImporter.h"
#include "../NastranFileType.h"
#include "../../Common/CommonMeshRepresentation.h"

using MeshIS::Model::Common::CMR;
using std::stringstream;
using std::string;

namespace MeshIS
{
namespace Model
{
namespace Import
{
    class NastranMeshImporter : public MeshImporter
    {
    private:
        std::unique_ptr<NastranParser> parser;
        static constexpr int COLUMN_LENGTH = 8;

        CMR parse(stringstream& stream);
        void shrink_to_fit_containers(CMR & mesh);

    public:
        virtual CMR   Import(const string & absolute_file_path);
        NastranMeshImporter(NastranFileType file_type);
    };

}//! end of namespace Import
}//! end of namespace Model
}//! end of namespace MeshIS

#endif // !NASTRAN_MESH_IMPORTER_H_
