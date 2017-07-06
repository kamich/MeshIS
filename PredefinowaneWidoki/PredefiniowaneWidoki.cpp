/* predefiniowane widoki
po klikniêciu prawym przyciskiem myszy otwiera siê menu, z którego mona wybraæ zdefiniowany 
widok - z lewej, przeniej, prawej, tylniej, górnej i delnej strony.
Ruch kamery by³ zadaniem innej osoby, ale zosta³ opracowany w p³aszczyŸnie x i z - kamer¹ poruszamy za pomoc¹ strza³ek.
*/

#include <windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

#define LEFT 1
#define FRONT 2
#define RIGHT 3
#define BACK 4
#define TOP 5
#define DOWN 6
#define PI 3.14159265359

// camera angle
float angle = 0.0;
// camera direction
float lx = 0.0f, ly = 0.0f, lz = -5.0f;
// camera position
float x = 0.0f, y = 0.0f,  z = 5.0f;

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black and opaque
	glClearDepth(1.0f);                   
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.01f;
		lx = sin(angle);
		//ly = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.01f;
		lx = sin(angle);
		//ly = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		//ly = ;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		//ly = ;
		z -= lz * fraction;
		break;
	}
}

void processMenuEvents(int option) {

	switch (option) {
	case LEFT:
		x = -5;
		y = 0;
		z = 0;
		lx = -x;
		ly = -y;
		lz = -z;
		angle = 90*PI / 180;
		break;
	case FRONT:
		x = 0;
		y = 0;
		z = 5;
		lx = -x;
		ly = -y;
		lz = -z;
		angle = 0;
		break;
	case RIGHT:
		x = 5;
		y = 0;
		z = 0;
		lx = -x;
		ly = -y;
		lz = -z;
		angle = 270 * PI / 180;
		break;
	case BACK:
		x = 0;
		y = 0;
		z = -5;
		lx = -x;
		ly = -y;
		lz = -z;
		angle = 180 * PI / 180;
		break;
	case TOP:
		x = 0;
		y = 5;
		z = 0.5;
		angle = 0 * PI / 180;
		lx = sin(angle);
		ly = -y;
		lz = -cos(angle);
		break;
	case DOWN:
		x = 0;
		y = -5;
		z = 0.5;
		angle = 0 * PI / 180;
		lx = sin(angle);
		ly = -y;
		lz = -cos(angle);
		break;
	}
}

void createGLUTMenus() {

	int menu;
	menu = glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("Left", LEFT);
	glutAddMenuEntry("Front", FRONT);
	glutAddMenuEntry("Right", RIGHT);
	glutAddMenuEntry("Back", BACK);
	glutAddMenuEntry("Top", TOP);
	glutAddMenuEntry("Down", DOWN);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 

	glLoadIdentity();                

	gluLookAt(x, y, z,
		x + lx , y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
	std::cout << angle << std::endl;

	glBegin(GL_QUADS);               
									
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	// Front face 
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// Back face
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	// Left face
	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	// Right face
	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();

	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {  
											   
	if (height == 0) height = 1;           
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();           
							
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);     
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(700, 700);  
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("MES");    

	glutReshapeFunc(reshape);       
	glutSpecialFunc(processSpecialKeys);               			
	createGLUTMenus();
	glutDisplayFunc(display);       
	glutIdleFunc(display);
	initGL();
	glutMainLoop();              
	return 0;
}