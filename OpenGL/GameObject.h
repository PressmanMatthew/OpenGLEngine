#pragma once
#include "Model.h"
#include "ComponentTypes.h"
#include "Component.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <set>

using glm::vec3;
using glm::mat4;
using std::set;
using std::vector;

struct Transform : Component {
	vec3 location, rotation, size;
	mat4 matrix;
};

enum Collider {
	colliderless,
	AABB,
	sphere
};

struct Rigidbody : Component {
	vec3 velocity;
	vec3 acceleration;
	vec3 force;
	float mass;
	Collider collider;
};

class GameObject
{
public:
	GameObject();
	~GameObject();

	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	GLuint texID;
	Model model;

	template <typename type> Component* AddComponent();
	template <typename type> Component* RemoveComponent();
	template <typename type> Component* GetComponent();

	Component* AddComponent(string type);
	Component* RemoveComponent(string type);
	Component* GetComponent(string type);

private:
	set<Component*> components;
};

template<typename type>
inline Component* GameObject::AddComponent()
{
	return Component();
}

template<typename type>
inline Component* GameObject::RemoveComponent()
{
	return Component();
}

template<typename type>
inline Component* GameObject::GetComponent()
{
	return Component();
}
