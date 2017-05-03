#define _CRT_SECURE_NO_DEPRECATE
#include "StatisticsDisplayer.h"
#include <string>
#include <iostream>
using namespace MeshIS::View;

StatisticsDisplayer::StatisticsDisplayer(MeshIS::Model::MeshStatistics const & stats)
{
	this->stats = stats;
	prepareMeshStats();
}

void StatisticsDisplayer::prepareMeshStats()
{
	double ratio = stats.avgT3Ratio;
	
	statTxts.push_back("Mesh average T3 ratio: " + std::to_string(ratio));
}

void StatisticsDisplayer::displayStatistics()
{
	glColor3d(0.0f, 0.0f, 0.0f);
	float x = 0.4f;
	float y = 1.2f;
	//int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	//int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	for (auto str : statTxts)
	{
		glRasterPos2f(x, y);
		glutBitmapString(font, reinterpret_cast<const unsigned char*>(str.c_str()));
		y -= 0.3;
	}

}


