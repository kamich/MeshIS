#include "ViewInitializer.h"
#include "StatisticsDisplayer.h"
#include <string>

using namespace MeshIS::View;

vector<function<void()>> renderFunctions;

void cleanWindow()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

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

	GLdouble aspect = 1;
	if (height > 0)
		aspect = width / (GLdouble)height;

	gluPerspective(fovy, aspect, 1.0, 5.0);
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

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		return err;
	}

	Element_T4 el{ 1.0,2.0,3.0,4.0 };
	Element_P6 el2{ 1.0,2.0,3.0,4.0,5.0,6.0 };
	Element_P6 el3{ 1.0,2.0,3.0,4.0,5.0,6.0 };

	CMR mesh;
	mesh.elementsT4.push_back(el);
	mesh.elementsP6.push_back(el2);
	mesh.elementsP6.push_back(el3);
	MeshIS::Model::MeshStatistic meshStats(mesh);
	StatisticsDisplayer stats(meshStats);
	ViewInitializer view;

	view.addFunction(std::bind(&StatisticsDisplayer::displayStatistics, stats));
	renderFunctions = view.getFunctionsToRender();

	glutMainLoop();
	return 0;
}