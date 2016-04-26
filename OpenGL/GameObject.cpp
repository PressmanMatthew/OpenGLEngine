#include "GameObject.h"

GameObject::GameObject()
{
	components = set<Component*>();

	components.insert(&Transform());
}


GameObject::~GameObject()
{
}

Component* GameObject::AddComponent(string type)
{
	if (ComponentTypes::possibleTypes.find(type) != ComponentTypes::possibleTypes.end())
	{
		if (type == "Transform")
		{
			Transform trans = Transform();
			components.insert(&trans);
			return &trans;
		}
		if (type == "Rigidbody")
		{
			Rigidbody rig = Rigidbody();
			components.insert(&rig);
			return &rig;
		}
	}
	return nullptr;
}

Component* GameObject::RemoveComponent(string type)
{
	if (ComponentTypes::possibleTypes.find(type) != ComponentTypes::possibleTypes.end())
	{
		
	}
	return nullptr;
}

Component* GameObject::GetComponent(string type)
{
	return nullptr;
}
