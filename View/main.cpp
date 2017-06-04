#include "ViewInitializer.h"
#include "StatisticsDisplayer.h"
#include "AppStartPoint.h"
#include "../Model/IO/State/StateManager.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <GL/glut.h>
#include <GL/glew.h>

using namespace MeshIS::View;
StateManager * stateManager;

void menu(int item)
{
    switch (item)
    {
        case AppStartPoint::SAVE_STATE:
            stateManager->saveState();
            break;
        case AppStartPoint::LOAD_STATE:
			const auto now{ std::chrono::system_clock::now() };
			const auto now_{ std::chrono::system_clock::to_time_t(now) };
			std::stringstream ss;
			ss << std::put_time(std::localtime(&now_), "%Y%m%d");
			std::string date = ss.str();
            CMR cmr = stateManager->loadState("CMR" + date + ".state");

			std::cout << "\n\n LOADED MESH \n";
			std::cout << "Vertices: " << cmr.vertices.size() << "\n Elements T3: " << cmr.elementsT3.size() << "\n Elements T4: " << cmr.elementsT4.size();
			std::cout << "\n Elements P6: " << cmr.elementsP6.size() << std::endl;
            break;

    }
}

int main(int argc, char* argv[])
{
    AppStartPoint app;
	CMR mesh;
	// test data
	Vertex ver = { 1.4,3.2,4 };
	Vertex ver2 = { 5.4,8.2,2 };
	Vertex ver3 = { 5.4,8.2,2 };
	Vertex ver4 = { 5.4,8.2,2 };
	Element_T3 e3 = { 1, 6, 6 };
	Element_T3 e3_2 = { 2, 6, 6 };
	Element_T4 e4 = { 1,4,4,4 };
	Element_T4 e4_2 = { 2,4,4,4 };
	Element_P6 e6 = { 1, 6, 6, 6, 6, 6 };
	Element_P6 e6_2 = { 2, 6, 6, 3, 6, 6 };

	mesh.vertices.push_back(ver);
	mesh.vertices.push_back(ver2);
	mesh.vertices.push_back(ver3);
	mesh.vertices.push_back(ver4);
	mesh.elementsT3.push_back(e3);
	mesh.elementsT3.push_back(e3_2);
	mesh.elementsP6.push_back(e6);
	mesh.elementsP6.push_back(e6_2);
	mesh.elementsT4.push_back(e4);
	mesh.elementsT4.push_back(e4_2);

	std::cout << "MESH AT THE BEGINNING \n";
	std::cout << "Vertices: " << mesh.vertices.size() << "\n Elements T3: " << mesh.elementsT3.size() << "\n Elements T4: " << mesh.elementsT4.size();
	std::cout << "\n Elements P6: " << mesh.elementsP6.size() << std::endl;
	stateManager = new StateManager(mesh);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("MeshIS");

    glutDisplayFunc(AppStartPoint::render);
    glutReshapeFunc(AppStartPoint::reshape);

    glutCreateMenu(menu);
    glutAddMenuEntry("Save current state", app.SAVE_STATE);
    glutAddMenuEntry("Load previous state", app.LOAD_STATE);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    ViewInitializer view;

	//test saving
	stateManager->saveState();

    glutMainLoop();
    return 0;
}
