#include "NeighbourSelections.h"
template<class T>
vector<T> * NeighbourSelections::neighbourSelectionsSimple(CMR & all, T& element) {
	std::set<T> selected;
	if (!element.empty()) {
		for (auto single : all.elementsP6) {
			for (int i = 0; i < single.size(); i++) {
				for (int j = 0; j < element.size(); j++) {
					if (single.at(i) == element.at(j)) {
						selected.instert(single);
					}
				}
			}
		}
		for (auto single : all.elementsT3) {
			for (int i = 0; i < single.size(); i++) {
				for (int j = 0; j < element.size(); j++) {
					if (single.at(i) == element.at(j)) {
						selected.instert(single);
					}
				}
			}
		}
		for (auto single : all.elementsT4) {
			for (int i = 0; i < single.size(); i++) {
				for (int j = 0; j < element.size(); j++) {
					if (single.at(i) == element.at(j)) {
						selected.instert(single);
					}
				}
			}
		}
	
		vector<T> allSelected;
		allSelected.assign(selected.begin(), selected.end());

		return &allSelected;
	}
	
}
template<class T>
vector<T> * NeighbourSelections::neighbourSelectionsMulti(CMR & all, vector<T> elements) {
	vector<T> allSelected;
	vector<T> temporary;
	for (int i = 0; i < elements.size(); i++) {
		temporary = NeighbourSelections::neighbourSelectionsSimple(all, elements.at(i));
		allSelected.insert(allSelected.end(), temporary);
		temporary.clear();
	}
	
		return &allSelected;
	}




