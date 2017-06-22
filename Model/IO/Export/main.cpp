#include <iostream>
#include "Unv_Export.h"
#include "CMR.h"


CMR cmr;

void loadExampleData() {//my own expample data
	cmr.vertices = { { 0,0,0 },{ 1,1,1 },{ -1,-1,-1 },{ 1,2,1 },{ 0,1,0 },{ 2,1,1 },{ -1,0,0 },{ 1,4,1 },{ 4,3,0 },{ 5,-1,1 } };
	cmr.elementsT4.pushback({ 1,2,3,4 });
	cmr.elementsT4.pushback({ 2,3,4,5 });
	cmr.elementsT4.pushback({ 5,6,1,7 });
	cmr.elementsT3.pushback({ 1,2,3 });
	cmr.elementsT3.pushback({ 3,4,5 });
	cmr.elementsT3.pushback({ 5,6,7 });

}
int main() {
	Unv_Export unv;
	loadExampleData();
	unv.Export("name_of_file", cmr);

	return 0;
}