#include "Engine.h"

Engine::Engine()
{
}


Engine::~Engine()
{
}

bool Engine::Init()
{
	if (glfwInit() == GL_FALSE)
	{
		return false;
	}
	
	GLFWwindowPtr = glfwCreateWindow(800, 600, "Matthew Pressman DSA1 Engine", NULL, NULL);


	if (GLFWwindowPtr != nullptr)
	{
		glfwMakeContextCurrent(GLFWwindowPtr);
	}
	else
	{
		glfwTerminate();
		return false;
	}

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return false;
	}
	
	return true;
}

bool Engine::BufferModel()
{
	vector<glm::vec3> locs = { { .9, .9, .9},
							   {-.9, .9, .9},
							   {-.9,-.9, .9},
							   { .9,-.9, .9},
							   { .9, .9,-.9}, 
							   {-.9, .9,-.9}, 
							   {-.9,-.9,-.9},
							   { .9,-.9,-.9} };

	vector<unsigned int> locInds = { 0, 1, 2,
									 0, 2, 3,
									 0, 1, 5,
									 0, 5, 4, 
									 0, 3, 7, 
									 0, 7, 4, 
									 6, 5, 4,
									 6, 4, 7, 
									 6, 7, 3, 
									 6, 3, 2, 
									 6, 5, 1, 
									 6, 1, 2};
	vertCount = locInds.size();
	vector <glm::vec3> vertBufData(vertCount);
	for (unsigned int i = 0; i < vertCount; i++)
	{
		vertBufData[i] = locs[locInds[i]];
	}
	GLuint vertBuf;

	glGenVertexArrays(1, &vertArr);
	glGenBuffers(1, &vertBuf);
	glBindVertexArray(vertArr);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertCount, &vertBufData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
	glBindVertexArray(0);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	return true;
}

bool Engine::UseShaders()
{
	shaderMng = ShaderManager();

	if (shaderMng.loadShaders("shaders/vShader.glsl", "shaders/fShader.glsl"))
	{
		glUseProgram(shaderMng.GetProgram());
		return true;
	}
	else
	{
		return false;
	}
}

bool Engine::GameLoop()
{
	//gluLookAt(0.0, 0.0, 2.8, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	while (!glfwWindowShouldClose(GLFWwindowPtr))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vertArr);
		glDrawArrays(GL_TRIANGLES, 0, vertCount);

		glfwSwapBuffers(GLFWwindowPtr);

		glfwPollEvents();
	}

	glfwTerminate();

	return true;
}
