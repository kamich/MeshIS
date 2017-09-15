#include "MergeManager.h"


namespace MeshIS
{
	namespace Model
	{


		Common::CMR MergeManager::Merge(Common::CMR &first, Common::CMR &second)
		{
			while (!first.vertices.empty())
			{
				unique.insert(first.vertices.back());
				first.vertices.pop_back();
			}

			while (!second.vertices.empty())
			{
				unique.insert(second.vertices.back());
				second.vertices.pop_back();
			}

			while (!unique.empty())
			{
				first.vertices.push_back(unique.end);
				unique.erase(first.vertices.back());
			}
			
			return first;
		}
	}
}