#include "ViewInitializer.h"
#include "StatisticsDisplayer.h"
#include <string>
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

	CMR mesh;
	StatisticsDisplayer stats(mesh);
	ViewInitializer view;

	view.addFunction(std::bind(&StatisticsDisplayer::displayStatistics, stats));
	renderFunctions = view.getFunctionsToRender();

	glutMainLoop();
	return 0;
}