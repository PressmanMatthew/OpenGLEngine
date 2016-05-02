#pragma once
#include <set>
#include <string>

using std::set;
using std::string;

struct ComponentTypes
{
	static void Init();

	static set<string> possibleTypes;
};

