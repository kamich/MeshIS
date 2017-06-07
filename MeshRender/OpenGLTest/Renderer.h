#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "../../Model/Common/CommonMeshRepresentation.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#include "VertexLoader.h"

using namespace glm;
using namespace MeshIS;
using namespace Model;
using namespace Common;
using namespace std;

class Renderer
{
public:

	Renderer() = default;
	~Renderer() = default;
	int loop(MeshIS::Model::Common::CommonMeshRepresentation common_mesh);
private:
	vector<float> commonToArray(MeshIS::Model::Common::CommonMeshRepresentation data);
};

