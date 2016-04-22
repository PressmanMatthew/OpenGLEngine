#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

using std::vector;

int main()
{
	//Initialize the window library
	if (glfwInit() == GL_FALSE)
	{
		return -1;
	}

	//Initialize Window
	GLFWwindow* GLFWwindowPtr = glfwCreateWindow(800, 600, "Matthew Pressman DSA1 Engine", NULL, NULL);
	if (GLFWwindowPtr != nullptr)
	{
		glfwMakeContextCurrent(GLFWwindowPtr);
	}
	else
	{
		glfwTerminate();
		return -1;
	}

	//Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	//Define the Quad
	vector<glm::vec3> locs = { { .9, .9, 0 },
	{ -.9, .9, 0 },
	{ -.9,-.9, 0 },
	{ .9,-.9, 0 },
	{ 0,  0, 0 } };

	vector<unsigned int> locInds = { 0, 1, 4,
									 2, 3, 4 };
	unsigned int vertCount = locInds.size();
	vector <glm::vec3> vertBufData(vertCount);
	for (unsigned int i = 0; i < vertCount; i++)
	{
		vertBufData[i] = locs[locInds[i]];
	}


	GLuint vertArr;

	//Where things are being buffered onto the card
	GLuint vertBuf;

	
	glGenBuffers(1, &vertBuf);
	glGenVertexArrays(1, &vertArr);
	glBindVertexArray(vertArr);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertCount, &vertBufData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
	glBindVertexArray(0);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(GLFWwindowPtr))
	{
		//Clear the canvas
		glClear(GL_COLOR_BUFFER_BIT);

		//Render game objects
		glBindVertexArray(vertArr);
		glDrawArrays(GL_TRIANGLES, 0, vertCount);
		glBindVertexArray(0);

		//Swap the front (what the screen is displaying) and the back (What OpenGL draws to) buffers.
		glfwSwapBuffers(GLFWwindowPtr);

		//Process queued window, mouse & keyboard callback events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}