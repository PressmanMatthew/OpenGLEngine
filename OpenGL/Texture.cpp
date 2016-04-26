#include "Texture.h"



Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::Load(const char* texFile)
{
	//Load in the image
	FIBITMAP* image = FreeImage_Load(FreeImage_GetFileType(texFile, 0), texFile);

	if (image == nullptr) return false;

	//Convert it to a 32 bit bitmap and then unload the old one
	FIBITMAP* image32 = FreeImage_ConvertTo32Bits(image);
	FreeImage_Unload(image);

	unsigned int texID;

	//Generate and bind the texture
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	//Add the texture ID to the list
	textures.push_back(texID);

	//Upload the texture to the graphics card
	glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB_ALPHA, FreeImage_GetWidth(image32), FreeImage_GetHeight(image32), 0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(image32));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//Unload the texture from RAM
	FreeImage_Unload(image32);

	//Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);

	//glUniform1i(2, 1);

	//glActiveTexture(GL_TEXTURE0 + 0);
	//glBindTexture(GL_TEXTURE_2D, texID);
}
