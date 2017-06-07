#include <stdio.h>
#include <stdlib.h>
#include "../../Model/Common/CommonMeshRepresentation.h"
#include "Renderer.h"
GLFWwindow* window;


int main(void)
{
	Renderer* renderer = new Renderer();
	MeshIS::Model::Common::CommonMeshRepresentation commonMesh;
	array<Vertex, 2> vertexes;
	vector<array<Vertex,2>> elements2D;
	//przykladowe dane; szescian
	
	vertexes[0] = { 0.,0.,0. };
	vertexes[1] = { 0.,1.,0. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 0.,1.,0. };
	vertexes[1] = { 1.,1.,0. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,1.,0. };
	vertexes[1] = { 1.,0.,0. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,0.,0. };
	vertexes[1] = { 0.,0.,0. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 0.,0.,0. };
	vertexes[1] = { 0.,0.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,0.,0. };
	vertexes[1] = { 1.,0.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 0.,1.,0. };
	vertexes[1] = { 0.,1.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,1.,0. };
	vertexes[1] = { 1.,1.,1. };
	elements2D.push_back(vertexes);

	vertexes[0] = { 0.,1.,1. };
	vertexes[1] = { 1.,1.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,1.,1. };
	vertexes[1] = { 1.,0.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 1.,0.,1. };
	vertexes[1] = { 0.,0.,1. };
	elements2D.push_back(vertexes);
	vertexes[0] = { 0.,0.,1. };
	vertexes[1] = { 0.,1.,1. };
	elements2D.push_back(vertexes);


	for (vector<array<Vertex, 2>>::iterator it = elements2D.begin(); it != elements2D.end(); ++it) {
		commonMesh.vertices.push_back((*it)[0]);
		commonMesh.vertices.push_back((*it)[1]);
	}
	
	renderer->loop(commonMesh);
	return 0;
}
