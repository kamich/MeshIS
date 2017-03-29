#include "VertexLoader.h"


VertexLoader::VertexLoader(const char * fname)
{
	std::fstream file(fname);
	float x, y, z, ign;
	int r, g, b;
	std::string toParse;
	if (file.is_open()) {
		while (file.good()) {
			file >> x;
			file >> y;
			file >> z;
			file >> ign;
			file >> r;
			file >> g;
			file >> b;
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);
		}
	}
}

VertexLoader::~VertexLoader()
{
}

const float* VertexLoader::getArray() const
{
	return vertices.data();
}
