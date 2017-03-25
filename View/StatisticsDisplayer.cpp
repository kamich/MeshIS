#define _CRT_SECURE_NO_DEPRECATE
#include "StatisticsDisplayer.h"
#include <string>

using namespace MeshIS::View;

StatisticsDisplayer::StatisticsDisplayer(MeshIS::Model::MeshStatistic stats)
{
	this->stats = stats;
	prepareMeshStats();
}

void StatisticsDisplayer::prepareMeshStats()
{
	int sizeEl4 = stats.el4.size();
	int sizeEl6 = stats.el6.size();
	
	statTxts.push_back("Amount of bad tetrahedral elements " + std::to_string(sizeEl4));
	statTxts.push_back("Amount of good tetrahedral elements " + std::to_string(stats.mesh.elementsT4.size() - sizeEl4));
	statTxts.push_back("Amount of bad Prismatic elements " + std::to_string(sizeEl6));
	statTxts.push_back("Amount of good Prismatic elements " + std::to_string(stats.mesh.elementsP6.size() - sizeEl6));
	//statTxts.push_back(std::to_string(sizeEl6));
}

void StatisticsDisplayer::displayStatistics()
{
	glColor3d(0.0f, 0.0f, 0.0f);
	float x = 1.5;
	float y = 2.7;
	//int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	//int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	for (auto str : statTxts)
	{
		glRasterPos2f(x, y);
		glutBitmapString(font, reinterpret_cast<const unsigned char*>(str.c_str()));
		y -= 0.3;
	}

}

