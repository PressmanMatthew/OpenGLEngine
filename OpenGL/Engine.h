#pragma once
#include "ShaderManager.h"
#include "Model.h"
#include "Texture.h"
#include "InputManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <vector>

using std::vector;
using glm::scale;
using glm::translate;
using glm::yawPitchRoll;

class Engine
{
public:
	Engine();
	~Engine();

	bool Init();
	bool BufferModels();
	bool LoadTexture();
	bool UseShaders();
	bool GameLoop();

private:
	GLFWwindow* GLFWwindowPtr;
	ShaderManager shaderMng;
	Model quad, arrowquad;
	Texture texture;
	vector<Object> objects;
};

