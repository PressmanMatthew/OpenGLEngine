#pragma once
#include "ShaderManager.h"
#include "ComponentTypes.h"
#include "Component.h"
#include "GameObject.h"
#include "Camera.h"
#include "Texture.h"
#include "InputManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <vector>
#include <cmath>;

using std::vector;
using glm::scale;
using glm::translate;
using glm::yawPitchRoll;

class Model;

class Engine
{
public:
	Engine();
	~Engine();

	bool Init();
	bool BufferModels();
	bool LoadTextures();
	bool UseShaders();
	bool GameLoop();

private:
	GLFWwindow* GLFWwindowPtr;
	ShaderManager shaderMng;
	Model quad, arrowquad;
	Texture texture;
	vector<GameObject> objects;
	Camera cam;
	float timeNow, timePrevious, deltaTime;
	const float F_GRAVITY = -0.05;
	const float WARIO_MOVE_FORCE = 5;
	const float WARIO_MAX_SPEED = .6;
	bool alive = true;

	bool Collides(const GameObject &obj1, const GameObject &obj2);
};

