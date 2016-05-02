#pragma once
#include "Component.h"
#include <glm/gtx/transform.hpp>

using glm::vec3;
using glm::mat4;

enum Collider {
	colliderless,
	AABB,
	sphere
};

struct Rigidbody : Component {
	Rigidbody();
	~Rigidbody();

	vec3 velocity;
	vec3 acceleration;
	vec3 force;
	float mass;
	Collider collider;
};

