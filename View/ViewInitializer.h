#ifndef ViewInitializer_H_
#define ViewInitializer_H_

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <functional>
#include <vector>

using std::vector;
using std::function;

class ViewInitializer
{
public:
	void addFunction(function<void()>);
	vector<function<void()>> getFunctionsToRender();

private:
	vector<function<void()>> renderFunctions;
};

#endif