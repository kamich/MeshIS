#include "Renderer.h"
#include "../../Model/Common/CommonMeshRepresentation.h"

extern GLFWwindow* window;


int Renderer::loop(MeshIS::Model::Common::CommonMeshRepresentation common_mesh)
{
	
	vector<float> glData = commonToArray(common_mesh);
	int verticesArraySize = glData.size();
	const float* arr = glData.data();

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	window = glfwCreateWindow(1024, 768, "OpenGL test 0.1", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);


	GLuint programID = LoadVertexShader("TransformVertexShader.vertexshader");
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	glColor3f(1, 1, 1);
	glPointSize(10.0);
	glLineWidth(25.0);


	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*verticesArraySize, arr, GL_STATIC_DRAW);

	do {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);


		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		//GLenum mode = GL_TRIANGLES;
		GLenum mode = GL_LINES;
		glDrawArrays(mode, 0, verticesArraySize);
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);

	glfwTerminate();
	return 0;
}


vector<float> Renderer::commonToArray(CommonMeshRepresentation data)
{
	vector < float > glData;
	//tetrahedrals
	for (Element_T4 element : data.elementsT4) {
		addElementToGlData(glData, element, data);
	}
	//prisms
	for (Element_P6 element : data.elementsP6) {
		addElementToGlData(glData, element, data);
	}
	return glData;
}

template<typename Element>
void Renderer::addElementToGlData(vector<float> & glData, Element element, CommonMeshRepresentation data) {
	for (int i = 0; i < element.size(); i++) {
		for (int j = 0; j <element.size(); j++) {
			//connect each vertex
			if (j != i) {
				Vertex vertex = data.vertices.at(element.at(i));
				pushVertexToGlData(glData, vertex);
				vertex = data.vertices.at(element.at(j));
				pushVertexToGlData(glData, vertex);
			}
		}
	}
}

void Renderer::pushVertexToGlData(vector<float> & glData, Vertex vertex) {
	for (std::array<double, 3>::iterator vertexIt = vertex.begin(); vertexIt != vertex.end(); ++vertexIt) {
		glData.push_back(*vertexIt);
	}
}