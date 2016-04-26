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

	//Add 18 blank objects
	for (int i = 0; i < 18; i++)
	{
		objects.push_back(Object());
	}

	//Give them Textures
	objects[0].texID = 1;
	objects[1].texID = 2;
	for (int i = 2; i < objects.size(); i++)
	{
		objects[i].texID = 3;
	}
	
	//Transforms 
	objects[0].transform.location = vec3(0, 0, -1);
	objects[0].transform.rotation = vec3(0, 0, 0);
	objects[0].transform.size = vec3(2, 2, 0);

	objects[1].transform.location = vec3(0, -.6, 0);
	objects[1].transform.rotation = vec3(0, 0, 0);
	objects[1].transform.size = vec3(.3, .4, 0);

	//Arrow Transforms
	float j = -.9;
	for (int i = 2; i < objects.size(); i++)
	{
		objects[i].transform.location = vec3(j, 1.5, 0);
		objects[i].transform.rotation = vec3(0, 0, 0);
		objects[i].transform.size = vec3(.2, .2, 0);
		if (j >= -.2 && j < .1) {
			j += .4;
		}
		else {
			j += .1;
		}
	}

	//Rigidbodies
	objects[1].rigidbody.velocity = vec3(0, 0, 0);
	objects[1].rigidbody.force = vec3(0, 0, 0);
	objects[1].rigidbody.mass = 1;

	for (int i = 2; i < objects.size(); i++)
	{
		objects[i].rigidbody.velocity = vec3(0, 0, 0);
		objects[i].rigidbody.force = vec3(0, 0, 0);
		objects[i].rigidbody.mass = .1;
	}

	timeNow = 0;
	timePrevious = 0;
	deltaTime = 0;
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
		timePrevious = timeNow;
		timeNow = glfwGetTime();
		deltaTime = timeNow - timePrevious;

		if (!InputManager::keyIsDown[GLFW_KEY_ESCAPE] && InputManager::keyWasDown[GLFW_KEY_ESCAPE])
		{
			glfwSetWindowShouldClose(GLFWwindowPtr, GL_TRUE);
		}

		if (!InputManager::keyIsDown[GLFW_KEY_D])
		{
			objects[1].rigidbody.force.x -= WARIO_MOVE_FORCE;
		}

		if (!InputManager::keyIsDown[GLFW_KEY_A])
		{
			objects[1].rigidbody.force.x += WARIO_MOVE_FORCE;
		}

		//Update Objects
		glClear(GL_COLOR_BUFFER_BIT);

		//Wario Control
		
		if (objects[1].rigidbody.velocity.x < .1 && objects[1].rigidbody.velocity.x > -.1)
		{
			objects[1].rigidbody.velocity.x = 0; //Stop Wario if He's going almost 0 velocity
		}
		if (objects[1].rigidbody.velocity.x > WARIO_MAX_SPEED)
		{
			objects[1].rigidbody.velocity.x = WARIO_MAX_SPEED; //Limit Wario from going to fast to the right
		}
		if (objects[1].rigidbody.velocity.x < -WARIO_MAX_SPEED)
		{
			objects[1].rigidbody.velocity.x = -WARIO_MAX_SPEED; //Limit Wario from going to fast to the left
		}
		if (objects[1].transform.location.x > .9)
		{
			objects[1].transform.location.x = .9;
			objects[1].rigidbody.velocity.x = 0;
		}
		else if (objects[1].transform.location.x < -.9)
		{
			objects[1].transform.location.x = -.9;
			objects[1].rigidbody.velocity.x = 0;
		}

		for (int i = 0; i < objects.size(); i++) {
			
			//Update Rigidbody
			if (objects[i].texID == 3)
			{
				objects[i].rigidbody.force.y += F_GRAVITY;
			}


			if (objects[i].texID != 1)
			{
				objects[i].rigidbody.velocity += ((objects[i].rigidbody.force / objects[i].rigidbody.mass) * deltaTime);
				objects[i].transform.location += objects[i].rigidbody.velocity * deltaTime;
			}

			//Update transform
			objects[i].transform.matrix = translate(objects[i].transform.location);
			objects[i].transform.matrix *= yawPitchRoll(objects[i].transform.rotation.y, objects[i].transform.rotation.x, objects[i].transform.rotation.z);
			objects[i].transform.matrix *= scale(objects[i].transform.size);
			glUniformMatrix4fv(3, 1, GL_FALSE, &objects[i].transform.matrix[0][0]);

			glBindTexture(GL_TEXTURE_2D, objects[i].texID);

			

			//Draw objects[i]ect
			if (objects[i].texID == 3)
			{
				arrowquad.Render();
			}
			else
			{
				quad.Render();
			}

			//Reset forces for the next frame
			objects[i].rigidbody.force = vec3(0, 0, 0);
		}
		

		glfwSwapBuffers(GLFWwindowPtr);

		InputManager::keyWasDown = InputManager::keyIsDown;
		glfwPollEvents();
	}

	glfwTerminate();

	return true;
}

