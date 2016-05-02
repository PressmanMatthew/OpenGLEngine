#pragma once
#include "Component.h"
#include <glm/gtx/transform.hpp>

using glm::vec3;
using glm::mat4;

struct Transform : public Component {
	Transform();
	~Transform();

	vec3 location, rotation, size;
	mat4 matrix;
};

