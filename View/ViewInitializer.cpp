#include "ViewInitializer.h"

using namespace MeshIS::View;

vector<function<void()>> ViewInitializer::getFunctionsToRender()
{
	return this->renderFunctions;
}

void ViewInitializer::addFunction(function<void()> function)
{
	renderFunctions.push_back(function);
}