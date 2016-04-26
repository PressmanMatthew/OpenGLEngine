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
	
	glfwSetMouseButtonCallback(GLFWwindowPtr, InputManager::MouseClick);
	glfwSetKeyCallback(GLFWwindowPtr, InputManager::KeyCallback);

	return true;
}

bool Engine::BufferModel()
{
	if (!model.Buffer("models/quad.obj")) return false;

	return true;
}

bool Engine::LoadTexture()
{
	if (!texture.Load("textures/tileable_stone_wall.jpg")) return false;
	if (!texture.Load("textures/tileable_brick_wall.jpg")) return false;
	if (!texture.Load("textures/tileable_grass.jpg")) return false;
	if (!texture.Load("textures/tileable_marble.jpg")) return false;

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
	int clicks = 0;
	while (!glfwWindowShouldClose(GLFWwindowPtr))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		if (!InputManager::keyIsDown[GLFW_KEY_ESCAPE] && InputManager::keyWasDown[GLFW_KEY_ESCAPE])
		{
			glfwSetWindowShouldClose(GLFWwindowPtr, GL_TRUE);
		}

		if (!InputManager::keyIsDown[GLFW_MOUSE_BUTTON_1] && InputManager::keyWasDown[GLFW_MOUSE_BUTTON_1])
		{
			clicks++;
		}

		InputManager::keyWasDown = InputManager::keyIsDown;

		glBindTexture(GL_TEXTURE_2D, (clicks % texture.textures.size()) + 1);

		model.Render();

		glfwSwapBuffers(GLFWwindowPtr);

		glfwPollEvents();
	}

	glfwTerminate();

	return true;
}
