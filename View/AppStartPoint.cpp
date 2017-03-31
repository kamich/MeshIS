#include "ViewInitializer.h"
#include "StatisticsDisplayer.h"
#include <string>
#include <iostream>
#include <GL/glut.h>
#include <GL/glew.h>
using namespace MeshIS::View;

vector<function<void()>> renderFunctions;

void cleanWindow()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT);
    gluPerspective(45.0,(double)600 / (double)800, 1.0, 200.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity();

	glTranslatef(0, 0, -3.0);
}

void render()
{
	cleanWindow();
	for (auto function : renderFunctions)
		function();


	glFlush();
	glutSwapBuffers();
}

GLdouble fovy = 90;

void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	render();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("MeshIS");

	glutDisplayFunc(render);
	glutReshapeFunc(Reshape);

	CMR mesh;

	MeshIS::Model::MeshStatistics meshStats(mesh);
    meshStats.processT3Elements();
	StatisticsDisplayer stats(meshStats);
	ViewInitializer view;

	view.addFunction(std::bind(&StatisticsDisplayer::displayStatistics, stats));
	renderFunctions = view.getFunctionsToRender();

	glutMainLoop();
	return 0;
}
