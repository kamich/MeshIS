#include "RemovingSelection.h"

CMR RemovingSelection::removeSelection(CMR & all){
	CMR toRemove = all;

	remove(toRemove.elementsP6);
	remove(toRemove.elementsT3);
	remove(toRemove.elementsT4);

	return toRemove;
}
template<class T>
void RemovingSelection::remove(T& elements){
	if (!elements.empty()) {
		for (auto &element : elements) {
			for (int i = 0; i < element.size(); i++) {
				element.at(i) = -1;
			}
		}
	}
}
