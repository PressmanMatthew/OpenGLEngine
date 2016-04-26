#pragma once
#include "ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

using std::vector;

class Engine
{
public:
	Engine();
	~Engine();

	bool Init();
	bool BufferModel();
	bool UseShaders();
	bool GameLoop();

private:
	GLFWwindow* GLFWwindowPtr;
	GLuint vertArr;
	unsigned int vertCount;
	ShaderManager shaderMng;
};

