//
// Created by Panda on 29.03.2017.
//

#ifndef  MeshStatistic_H_
#define  MeshStatistic_H_

#include "../Common/CommonMeshRepresentation.h"

using namespace MeshIS::Model::Common;

namespace MeshIS
{
    namespace Model
    {
        class MeshStatistics
        {
        public:
            MeshStatistics() {};
            MeshStatistics(CMR cmr) { this->cmr = cmr; };
            void processT3Elements();
            double avgT3Ratio;
        private:
//Elements, which might be wrong considering their inscribed/enscribed circle ratio
            vector<Element_T3> t3;
            CMR cmr;

        };
typedef MeshStatistics MS;
    }
}
#endif