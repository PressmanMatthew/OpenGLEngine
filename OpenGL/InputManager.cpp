#include "InputManager.h"



map<int, bool> InputManager::keyIsDown;
map<int, bool> InputManager::keyWasDown;

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::MouseClick(GLFWwindow * windowPtr, int button, int action, int mods)
{
	keyIsDown[button] = action;
}

void InputManager::KeyCallback(GLFWwindow * windowPtr, int key, int scancode, int action, int mods)
{
	keyIsDown[key] = action;
}
