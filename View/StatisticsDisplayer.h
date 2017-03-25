#ifndef StatisticsDisplayer_H_
#define StatisticsDisplayer_H_

#include "Model\Common\CommonMeshRepresentation.h"
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace MeshIS::Model::Common;

class StatisticsDisplayer
{
public:
	StatisticsDisplayer(CMR);
	void displayStatistics();

private:
	CMR mesh;
	void prepareMeshStats();
	void * font = GLUT_BITMAP_HELVETICA_12;
};

#endif