#include "ViewInitializer.h"
#include "StatisticsDisplayer.h"
#include "AppStartPoint.h"
#include "../Model/IO/State/StateManager.h"
#include <string>
#include <iostream>
#include <GL/glut.h>
#include <GL/glew.h>
using namespace MeshIS::View;


vector<function<void()>>AppStartPoint::renderFunctions;

void AppStartPoint::cleanWindow()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT);
    gluPerspective(45.0,(double)600 / (double)800, 1.0, 200.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity();

	glTranslatef(0, 0, -3.0);
}

void AppStartPoint::render()
{
	cleanWindow();
	for (auto function : renderFunctions)
		function();


	glFlush();
	glutSwapBuffers();
}

GLdouble fovy = 90;

void AppStartPoint::reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	render();
}

void AppStartPoint::setFunctionsToRender(vector<function<void()>> const & fun)
{
	renderFunctions = fun;
}
