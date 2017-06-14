//*************************
//Created by Dominik Kopaczka
//*************************

#include<string>
#include "../../../../Common/CommonMeshRepresentation.h"

#ifndef CPPWINLIN_BULKDATA_H
#define CPPWINLIN_BULKDATA_H

using std::string;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::Element_T4;
using MeshIS::Model::Common::Element_P6;
namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{
			namespace Nastran
			{
				namespace BData
				{
					/*
						This class is abstract. Using this class in NastranExporter, I can use only 
						pointer to BulkData and set it up depending on selected enum class type.
						This class and using polymorphism makes development code easier 
						for Karol Kiełbasa and Damian Nowak.
					*/
					class BulkData
					{
					//Virtual Methods Using To Get Line Of Bulk Data//
					public: string virtual get_GRID_line_from_vertex(Vertex vertex, int vertexID) = 0;
					public: string virtual get_CTETRA_line_from_elementT4(Element_T4 elementT4, int elementID) = 0;
					public: string virtual get_CPENTA_line_from_elementP6(Element_P6 elementP6, int elementID) = 0;
					//////////////////////////////////////////////////
					};
				}
			}
		}
	}
}

#endif //CPP_BULKDATA_H