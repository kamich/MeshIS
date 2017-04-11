#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <CommonMeshRepresentation.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
using namespace MeshIS;
using namespace Model;
using namespace Common;

#include "shader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#include "VertexLoader.h"

using namespace glm;
using namespace MeshIS;
using namespace Model;
using namespace Common;

class Renderer
{
public:

	Renderer();
	~Renderer();
	int loop(MeshIS::Model::Common::CommonMeshRepresentation common_mesh);
private:
	float* commonToArray(CommonMeshRepresentation data);
};

