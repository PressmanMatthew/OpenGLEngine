#include "ComponentTypes.h"

set<string> ComponentTypes::possibleTypes;

void ComponentTypes::Init()
{
	possibleTypes = set<string>();

	possibleTypes.insert("Transform");
	possibleTypes.insert("Rigidbody");
	possibleTypes.insert("Model");
	possibleTypes.insert("Texture");
}
