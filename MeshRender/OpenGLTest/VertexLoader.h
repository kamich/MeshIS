#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "GL/glew.h"

#include <CommonMeshRepresentation.h>
class VertexLoader
{
public:
	VertexLoader(const char* fname);
	~VertexLoader();
	const float* getArray() const;
	const unsigned getSize() { return vertices.size(); }
private:
	float maxVal;
	std::vector<float> vertices;
};

