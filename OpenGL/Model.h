#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using glm::vec2;
using glm::vec3;
using glm::mat4;
using std::vector;
using std::string;
using std::ifstream;

class Model
{
public:
	Model();
	~Model();

	bool Buffer(string objFile);
	void Render();
private:
	GLuint vertArr;
	unsigned int vertCount;
};

struct Vertex {
	vec3 location;
	vec2 uv;
	vec3 normal;
};

struct VertInd {
	unsigned int locInd;
	unsigned int uvInd;
	unsigned int normInd;
};

struct Transform {
	vec3 location, rotation, size;
	mat4 matrix;
};

struct Object {
	Transform transform;
	GLuint texID;
};