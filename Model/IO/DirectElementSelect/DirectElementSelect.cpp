#include"DirectElementSelect.h"

template<class T>
std::vector<T> DirectElementSelection::directSelect(CMR & data, std::vector<int> verticesID)
{
	if (verticesID.size() > 0) {
		std::vector<T> selected;

		for (int i = 0; i < verticesID.size(); ++i) {
			for (auto element : data.elementsT4) {
				for (int j = 0; j < element.size(); ++j) {
					if (verticesID[i] == element[j]) selected.push_back(element);
				}
			}

			for (auto element : data.elementsT3) {
				for (int j = 0; j < element.size(); ++j) {
					if (verticesID[i] == element[j]) selected.push_back(element);
				}
			}

			for (auto element : data.elementsP6) {
				for (int j = 0; j < element.size(); ++j) {
					if (verticesID[i] == element[j]) selected.push_back(element);
				}
			}
		}

		return selected;
	}
	return -1;
}
