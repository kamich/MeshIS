#include "StateManager.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>

using std::ofstream;
using std::ifstream;


StateManager::StateManager(CMR & cmr) : trackingCMR(cmr)
{
};

bool StateManager::saveState()
{
    const auto now{std::chrono::system_clock::now()};
    const auto now_{std::chrono::system_clock::to_time_t(now)};
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_), "%Y%m%d");
	std::string date = ss.str();
    ofstream file("CMR" + date + ".state");;
	if (file.good())
	{
		file.write((char *)&trackingCMR, sizeof(trackingCMR));
		int size = trackingCMR.elementsP6.size();
		file.close();
		return true;
	}
	else
		return false;
    
}

CMR StateManager::loadState(std::string fileName)
{
	CMR cmr;
    ifstream file;
    file.open(fileName);
	file.read((char *)&cmr, sizeof(cmr));
    return cmr;
}

