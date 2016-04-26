#include "Engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

using std::vector;


int main()
{
	Engine eng = Engine();
	/*char* str = glGetString(GL_VERSION);

	cout << glGetString(GL_VERSION);*/

	if (!eng.Init())
	{
		return -1;
	}
	if (!eng.BufferModel())
	{
		return -1;
	}

	if (eng.UseShaders())
	{
		eng.GameLoop();
	}

	return 0;
}