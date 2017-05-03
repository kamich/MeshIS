#ifndef StatisticsDisplayer_H_
#define StatisticsDisplayer_H_

#include "../Model/Mesh_Statistics/MeshStatistics.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

namespace MeshIS
{
	namespace View
	{

		class StatisticsDisplayer
		{
		public:
			StatisticsDisplayer(MeshIS::Model::MeshStatistics const &);
			void displayStatistics();

		
			MeshIS::Model::MeshStatistics stats;
			void prepareMeshStats();
			void * font = GLUT_BITMAP_HELVETICA_12;
			vector<std::string> statTxts;
		};

	}
}
#endif
