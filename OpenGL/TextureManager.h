#pragma once
#include <map>
#include <string>

using std::map;
using std::string;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static map<string, unsigned int> textures;
};

