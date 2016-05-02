#include "Camera.h"



Camera::Camera()
{
	transform.location = vec3(0, 0, 2);
	transform.rotation = vec3(0, 0, 0);

	//Initialize the View Matrix
	vec3 camLoc = transform.location;
	vec3 camRot = transform.rotation;

	mat3 rotMat = (mat3)yawPitchRoll(camRot.y, camRot.x, camRot.z);

	vec3 eye = camLoc;
	vec3 center = eye + rotMat * vec3(0, 0, -1);
	vec3 up = rotMat * vec3(0, 1, 0);

	mat4 lookAtMat = lookAt(eye, center, up);

	//Initialize the Perspective Matrix
	float zoom = 1.0f;
	int width = 800;
	int height = 600;

	fovy = 3.14159f * .4f / zoom;
	aspect = (float)width / (float)height;
	zNear = 0.01f;
	zFar = 1000.0f;

	mat4 perspectiveMat = perspective(fovy, aspect, zNear, zFar);

	camera = perspectiveMat * lookAtMat;
}


Camera::~Camera()
{
}

void Camera::Update(vec3 force)
{
	rigidbody.force = force;
	transform.location += rigidbody.force;

	//Initialize the View Matrix
	vec3 camLoc = transform.location;
	vec3 camRot = transform.rotation;

	mat3 rotMat = (mat3)yawPitchRoll(camRot.y, camRot.x, camRot.z);

	vec3 eye = camLoc;
	vec3 center = eye + rotMat * vec3(0, 0, -1);
	vec3 up = rotMat * vec3(0, 1, 0);

	mat4 lookAtMat = lookAt(eye, center, up);

	mat4 perspectiveMat = perspective(fovy, aspect, zNear, zFar);

	camera = perspectiveMat * lookAtMat;

	glUniformMatrix4fv(4, 1, GL_FALSE, &camera[0][0]);
}
