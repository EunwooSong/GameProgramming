#pragma once
#include "Define.h"
#include "Texture.h"

class TextureManager
{
private:
	std::map<char*, Texture*> textureMap;
	//std::map <char*, >

public:
	TextureManager();
	~TextureManager();

	Texture* LoadTextureFromFile(char* path);
};

