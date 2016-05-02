#pragma once
#include "Engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <map>

using std::map;

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void MouseClick(GLFWwindow *windowPtr, int button, int action, int mods);
	static void KeyCallback(GLFWwindow *windowPtr, int key, int scancode, int action, int mods);

	static map<int, bool> keyIsDown;
	static map<int, bool> keyWasDown;
};

