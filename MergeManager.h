#pragma once
#ifndef MESHIS_PROPERITIES_MANAGER_H_
#define MESHIS_PROPERITIES_MANAGER_H_

#include "../../Common/CommonMeshRepresentation.h"
#include <set>
using namespace MeshIS::Model::Common;
namespace MeshIS
{
	namespace Model
	{
			class MergeManager
			{
				std::set < array<double, 3>> unique;
			

			public:
				Common::CMR Merge(Common::CMR &,  Common::CMR &);

			};
	}
}

#endif