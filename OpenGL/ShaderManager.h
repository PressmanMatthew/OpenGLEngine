#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ifstream;
using std::cout;

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	GLuint GetProgram() const;

	bool loadShaders(const char* vertexFile, const char* fragmentFile);

private:
	GLuint program;

	GLuint loadShader(const char* file, GLenum shaderType);
};

