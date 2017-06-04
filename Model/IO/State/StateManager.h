#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include "../../Common/CommonMeshRepresentation.h"
#include <string>

using MeshIS::Model::Common::CMR;

class StateManager
{
public:
    StateManager(CMR & cmr);
    bool saveState();
    CMR loadState(std::string fileName);

private:
    CMR & trackingCMR;
};

#endif