#include "GameObject.h"
#include <iostream>

template<typename type>
inline Component* GameObject::AddComponent(type* component)
{
	//if (component->gameObject != NULL)
	//	return;
	auto type = comp

	return components[0];
}

template<typename type>
inline Component* GameObject::RemoveComponent()
{
	return NULL;
}

template<typename type>
inline Component* GameObject::GetComponent()
{
	return NULL;
}

GameObject::GameObject()
{
	components = vector<Component*>();

	Transform trans = Transform();
	components.push_back(&trans);

	transform.location = vec3();
	transform.rotation = vec3();
	transform.size = vec3(1, 1, 1);
}


GameObject::~GameObject()
{
}

//Component* GameObject::AddComponent(string type)
//{
//	if (ComponentTypes::possibleTypes.find(type) != ComponentTypes::possibleTypes.end())
//	{
//		if (type == "Transform")
//		{
//			bool exists = false;
//			for (size_t i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Transform))
//				{
//					exists = true;
//				}
//			}
//			if (!exists)
//			{
//				Transform trans = Transform();
//				components.insert(components.end(), &trans);
//				return &trans;
//			}
//		}
//		else if (type == "Rigidbody")
//		{
//			bool exists = false;
//			for (size_t i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Rigidbody))
//				{
//					exists = true;
//				}
//			}
//			if (!exists)
//			{
//				Rigidbody rig = Rigidbody();
//				components.insert(components.end(), &rig);
//				return &rig;
//			}
//		}
//		else if (type == "Model")
//		{
//			bool exists = false;
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Model))
//				{
//					exists = true;
//				}
//			}
//			if (!exists)
//			{
//				Model mod = Model();
//				components.insert(components.end(), &mod);
//				return &mod;
//			}
//		}
//		else if (type == "Texture")
//		{
//			bool exists = false;
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Texture))
//				{
//					exists = true;
//				}
//			}
//			if (!exists)
//			{
//				Texture tex = Texture();
//				components.insert(components.end(), &tex);
//				return &tex;
//			}
//		}
//	}
//	return nullptr;
//}
//
//bool GameObject::RemoveComponent(string type)
//{
//	if (ComponentTypes::possibleTypes.find(type) != ComponentTypes::possibleTypes.end())
//	{
//		if (type == "Transform")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Transform))
//				{
//					components.erase(components.begin() + i);
//				}
//			}
//			return true;
//		}
//		if (type == "Rigidbody")
//		{
//			if (components.size() > 1)
//			{
//				for (int i = 0; i < components.size(); i++)
//				{
//					if (typeid(components[i]) == typeid(Rigidbody))
//					{
//						components.erase(components.begin() + i);
//					}
//				}
//				return true;
//			}
//		}
//		if (type == "Model")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Model))
//				{
//					components.erase(components.begin() + i);
//				}
//			}
//		}
//		if (type == "Texture")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Texture))
//				{
//					components.erase(components.begin() + i);
//				}
//			}
//		}
//	}
//	return false;
//}
//
//Component* GameObject::GetComponent(string type)
//{
//	if (ComponentTypes::possibleTypes.find(type) != ComponentTypes::possibleTypes.end())
//	{
//		if (type == "Transform")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Transform))
//				{
//					return components[i];
//				}
//			}
//		}
//		else if (type == "Rigidbody")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Rigidbody))
//				{
//					return components[i];
//				}
//			}
//		}
//		else if (type == "Model")
//		{
//			for (size_t i = 0; i < components.size(); i++)
//			{
//				std::cout << typeid(dynamic_cast<Model*>(components[i])).name();
//				if (typeid(dynamic_cast<Model*>(components[i])) == typeid(Model*))
//				{
//					return components[i];
//				}
//			}
//		}
//		else if (type == "Texture")
//		{
//			for (int i = 0; i < components.size(); i++)
//			{
//				if (typeid(components[i]) == typeid(Texture))
//				{
//					return components[i];
//				}
//			}
//		}
//	}
//	return nullptr;
//}
