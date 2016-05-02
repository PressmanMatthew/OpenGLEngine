#pragma once
#include "Model.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Texture.h"
#include "ComponentTypes.h"
#include "Component.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <map>
#include <typeindex>

using glm::vec3;
using glm::mat4;
using std::vector;
using std::map;
using std::pair;
using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();

	//To be depricated
	Transform transform;
	Rigidbody rigidbody;
	GLuint texID;
	Model model;

	//New system to be implemented
	template <typename type> Component* AddComponent(type* component);
	template <typename type> Component* RemoveComponent();
	template <typename type> Component* GetComponent();

	//Component* AddComponent(string type);
	//bool RemoveComponent(string type);
	//Component* GetComponent(string type);

private:
	vector<Component*> components;//map<type_index, vector<Component*>> components;
};
