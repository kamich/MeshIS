#ifndef  MeshStatistic_H_
#define  MeshStatistic_H_

#include "Model\Common\CommonMeshRepresentation.h"

using namespace MeshIS::Model::Common;

namespace MeshIS
{
	namespace Model
	{

		// Just temporary, until task with statistic model is not finished 
		class MeshStatistic
		{
		public:
			MeshStatistic() {};
			MeshStatistic(CMR mesh) { this->mesh = mesh; };
			vector<Element_T4> el4;
			vector<Element_P6> el6;
			CMR mesh;
		};

	}
}
#endif 
