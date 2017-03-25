#ifndef StatisticsDisplayer_H_
#define StatisticsDisplayer_H_

#include "MeshStatistic.h"
#include <GL\glew.h>
#include <GL\freeglut.h>

namespace MeshIS
{
	namespace View
	{

		class StatisticsDisplayer
		{
		public:
			StatisticsDisplayer(MeshIS::Model::MeshStatistic);
			void displayStatistics();

		private:
			MeshIS::Model::MeshStatistic stats;
			void prepareMeshStats();
			void * font = GLUT_BITMAP_HELVETICA_12;
			vector<std::string> statTxts;
		};

	}
}
#endif