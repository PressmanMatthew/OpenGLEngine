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

	objects.push_back(Object());
	objects.push_back(Object());
	
	//Arrows
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());
	objects.push_back(Object());

	objects[0].texID = 1;
	objects[1].texID = 2;
	objects[2].texID = 3;
	objects[3].texID = 3;
	objects[4].texID = 3;
	objects[5].texID = 3;
	objects[6].texID = 3;
	objects[7].texID = 3;
	objects[8].texID = 3;
	objects[9].texID = 3;
	objects[10].texID = 3;
	objects[11].texID = 3;
	objects[12].texID = 3;
	objects[13].texID = 3;
	objects[14].texID = 3;
	objects[15].texID = 3;
	objects[16].texID = 3;
	objects[17].texID = 3;
	
	objects[0].transform.location = vec3(0, 0, -1);
	objects[0].transform.rotation = vec3(0, 0, 0);
	objects[0].transform.size = vec3(2, 2, 0);

	objects[1].transform.location = vec3(0, -.6, 0);
	objects[1].transform.rotation = vec3(0, 0, 0);
	objects[1].transform.size = vec3(.3, .4, 0);

	//Arrows

	objects[2].transform.location = vec3(-.9, .6, 0);
	objects[2].transform.rotation = vec3(0, 0, 0);
	objects[2].transform.size = vec3(.2, .2, 0);

	objects[3].transform.location = vec3(-.8, .6, 0);
	objects[3].transform.rotation = vec3(0, 0, 0);
	objects[3].transform.size = vec3(.2, .2, 0);

	objects[4].transform.location = vec3(-.7, .6, 0);
	objects[4].transform.rotation = vec3(0, 0, 0);
	objects[4].transform.size = vec3(.2, .2, 0);

	objects[5].transform.location = vec3(-.6, .6, 0);
	objects[5].transform.rotation = vec3(0, 0, 0);
	objects[5].transform.size = vec3(.2, .2, 0);

	objects[6].transform.location = vec3(-.5, .6, 0);
	objects[6].transform.rotation = vec3(0, 0, 0);
	objects[6].transform.size = vec3(.2, .2, 0);

	objects[7].transform.location = vec3(-.4, .6, 0);
	objects[7].transform.rotation = vec3(0, 0, 0);
	objects[7].transform.size = vec3(.2, .2, 0);

	objects[8].transform.location = vec3(-.3, .6, 0);
	objects[8].transform.rotation = vec3(0, 0, 0);
	objects[8].transform.size = vec3(.2, .2, 0);

	objects[9].transform.location = vec3(-.2, .6, 0);
	objects[9].transform.rotation = vec3(0, 0, 0);
	objects[9].transform.size = vec3(.2, .2, 0);

	objects[10].transform.location = vec3(.2, .6, 0);
	objects[10].transform.rotation = vec3(0, 0, 0);
	objects[10].transform.size = vec3(.2, .2, 0);

	objects[11].transform.location = vec3(.3, .6, 0);
	objects[11].transform.rotation = vec3(0, 0, 0);
	objects[11].transform.size = vec3(.2, .2, 0);

	objects[12].transform.location = vec3(.4, .6, 0);
	objects[12].transform.rotation = vec3(0, 0, 0);
	objects[12].transform.size = vec3(.2, .2, 0);

	objects[13].transform.location = vec3(.5, .6, 0);
	objects[13].transform.rotation = vec3(0, 0, 0);
	objects[13].transform.size = vec3(.2, .2, 0);

	objects[14].transform.location = vec3(.6, .6, 0);
	objects[14].transform.rotation = vec3(0, 0, 0);
	objects[14].transform.size = vec3(.2, .2, 0);

	objects[15].transform.location = vec3(.7, .6, 0);
	objects[15].transform.rotation = vec3(0, 0, 0);
	objects[15].transform.size = vec3(.2, .2, 0);

	objects[16].transform.location = vec3(.8, .6, 0);
	objects[16].transform.rotation = vec3(0, 0, 0);
	objects[16].transform.size = vec3(.2, .2, 0);

	objects[17].transform.location = vec3(.9, .6, 0);
	objects[17].transform.rotation = vec3(0, 0, 0);
	objects[17].transform.size = vec3(.2, .2, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

bool Engine::BufferModels()
{
	if (!quad.Buffer("models/quad.obj")) return false;
	if (!arrowquad.Buffer("models/arrowquad.obj")) return false;

	return true;
}

bool Engine::LoadTexture()
{
	if (!texture.Load("textures/background.jpg")) return false;
	if (!texture.Load("textures/wario.png")) return false;
	if (!texture.Load("textures/arrow.png")) return false;

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

		if (!InputManager::keyIsDown[GLFW_KEY_ESCAPE] && InputManager::keyWasDown[GLFW_KEY_ESCAPE])
		{
			glfwSetWindowShouldClose(GLFWwindowPtr, GL_TRUE);
		}

		for each( Object obj in objects)
		{
			obj.transform.matrix = translate(obj.transform.location);
			obj.transform.matrix *= yawPitchRoll(obj.transform.rotation.y, obj.transform.rotation.x, obj.transform.rotation.z);
			obj.transform.matrix *= scale(obj.transform.size);
			glUniformMatrix4fv(3, 1, GL_FALSE, &obj.transform.matrix[0][0]);
			
			glBindTexture(GL_TEXTURE_2D, obj.texID);
			if (obj.texID == 3)
			{
				arrowquad.Render();
			}
			else
			{
				quad.Render();
			}
		}
		

		glfwSwapBuffers(GLFWwindowPtr);

		InputManager::keyWasDown = InputManager::keyIsDown;
		glfwPollEvents();
	}

	glfwTerminate();

	return true;
}
