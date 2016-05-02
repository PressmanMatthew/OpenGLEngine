#pragma once
#include "TextureManager.h"
#include "Component.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <map>
#include <string>

using std::map;
using std::string;

struct Texture : Component
{
	Texture();
	~Texture();

	string name;
	unsigned int texID;

	bool Load(const char* texFile);
};

