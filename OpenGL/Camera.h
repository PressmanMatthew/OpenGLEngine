#pragma once
#include "GameObject.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using glm::mat3;
using glm::vec3;
using glm::yawPitchRoll;
using glm::lookAt;
using glm::perspective;

class Camera : public GameObject
{
public:
	Camera();
	~Camera();

	mat4 camera;
	float fovy;
	float aspect;
	float zNear;
	float zFar;

	void Update(vec3 force);
};

