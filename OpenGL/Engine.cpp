#include "Engine.h"

Engine::Engine()
{
}


Engine::~Engine()
{
	/*while (texture.textures.size != 0)
	{
		glDeleteTextures(1, &texture.textures[texture.textures.size]);
	}*/
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
	if (!model.Buffer("models/quad.obj")) return false;

	return true;
}

bool Engine::LoadTexture()
{
	if (!texture.Load("textures/tileable_stone_wall.jpg")) return false;

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
	while (!glfwWindowShouldClose(GLFWwindowPtr))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		model.Render();

		glfwSwapBuffers(GLFWwindowPtr);

		glfwPollEvents();
	}

	glfwTerminate();

	return true;
}
