#include <stdio.h>
#include <stdlib.h>
#include <CommonMeshRepresentation.h>
#include "Renderer.h"
GLFWwindow* window;


int main(void)
{
	Renderer* renderer = new Renderer();
	MeshIS::Model::Common::CommonMeshRepresentation commonMesh;
	Vertex vertex;
	//przykladowe dane; szescian
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 100; i++)
		{
			vertex[j] = (double)i / 20.;
			vertex[(j+1)%3] = 0.;
			vertex[(j+2)%3] = 0.;
			commonMesh.vertices.push_back(vertex);
		}
		for (int i = 0; i < 100; i++)
		{
			vertex[j] = (double)i / 20.;
			vertex[(j + 1) % 3] = 5.;
			vertex[(j + 2) % 3] = 0.;
			commonMesh.vertices.push_back(vertex);
		}
		for (int i = 0; i < 100; i++)
		{
			vertex[j] = (double)i / 20.;
			vertex[(j + 1) % 3] = 0.;
			vertex[(j + 2) % 3] = 5.;
			commonMesh.vertices.push_back(vertex);
		}
		for (int i = 0; i < 100; i++)
		{
			vertex[j] = (double)i / 20.;
			vertex[(j + 1) % 3] = 5.;
			vertex[(j + 2) % 3] = 5.;
			commonMesh.vertices.push_back(vertex);
		}
	}
	/*for (int i = 0; i < 100; i++)
	{
		vertex[0] = (double)i / 20.;
		vertex[1] = 0.;
		vertex[2] = 0.;
		commonMesh.vertices.push_back(vertex);
	}
	for (int i = 0; i < 100; i++)
	{
		vertex[0] = 0.;
		vertex[1] = (double)i / 20.;
		vertex[2] = 0.;
		commonMesh.vertices.push_back(vertex);
	}
	for (int i = 0; i < 100; i++)
	{
		vertex[0] = 0.;
		vertex[1] = 0.;
		vertex[2] = (double)i / 20.;
		commonMesh.vertices.push_back(vertex);
	}*/

	renderer->loop(commonMesh);
	return 0;
}
