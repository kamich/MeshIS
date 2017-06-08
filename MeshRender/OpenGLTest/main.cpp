#include <stdio.h>
#include <stdlib.h>
#include "../../Model/Common/CommonMeshRepresentation.h"
#include "Renderer.h"
GLFWwindow* window;


MeshIS::Model::Common::CommonMeshRepresentation makePrism() {
	MeshIS::Model::Common::CommonMeshRepresentation commonMesh;

	//przykladowe dane; prism
	commonMesh.vertices.push_back(Vertex{ 0.,0.,0. });
	commonMesh.vertices.push_back(Vertex{ 2.,0.,0. });
	commonMesh.vertices.push_back(Vertex{ 1.,2,0. });
	commonMesh.vertices.push_back(Vertex{ 0.,0.,2. });
	commonMesh.vertices.push_back(Vertex{ 2.,0.,2. });
	commonMesh.vertices.push_back(Vertex{ 1.,2,2. });

	commonMesh.elementsP6.push_back(Element_P6{ 0,1,2,3,4,5 });
	
	return commonMesh;
}

MeshIS::Model::Common::CommonMeshRepresentation makeTetrahedral() {
	MeshIS::Model::Common::CommonMeshRepresentation commonMesh;

	//przykladowe dane; tetrahedral
	commonMesh.vertices.push_back(Vertex{ 0.,0.,0. });
	commonMesh.vertices.push_back(Vertex{ 1.,0.,1. });
	commonMesh.vertices.push_back(Vertex{ -1.,0.,1. });
	commonMesh.vertices.push_back(Vertex{ 0.,1.,1. });

	commonMesh.elementsT4.push_back(Element_T4{ 0,1,2,3 });
	return commonMesh;
}

int main(void)
{
	Renderer* renderer = new Renderer();

	//do wyboru do koloru
	//MeshIS::Model::Common::CommonMeshRepresentation commonMesh = makePrism();
	MeshIS::Model::Common::CommonMeshRepresentation commonMesh = makeTetrahedral();

	renderer->loop(commonMesh);
	return 0;
}
