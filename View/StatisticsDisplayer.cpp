#define _CRT_SECURE_NO_DEPRECATE
#include "StatisticsDisplayer.h"

StatisticsDisplayer::StatisticsDisplayer(CMR mesh)
{
	this->mesh = mesh;
}

void StatisticsDisplayer::displayStatistics()
{
	glRasterPos2f(1.0, 0.0);
	glColor3d(0.0f, 0.0f, 0.0f);

	std::string myString = "Test";
	glutBitmapString(font, reinterpret_cast<const unsigned char*>(myString.c_str()));

}