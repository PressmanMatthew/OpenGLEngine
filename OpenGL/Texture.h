#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

using std::vector;

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const char* texFile);
	vector <unsigned int> textures;
};

