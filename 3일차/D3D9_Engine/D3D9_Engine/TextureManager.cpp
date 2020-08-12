#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

Texture* TextureManager::LoadTextureFromFile(char* path)
{
	if (textureMap[path] == NULL) {
		textureMap[path] = new Texture();

		D3DXCreateTextureFromFileExA(
			pd3dDevice,
			path,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			NULL,
			&textureMap[path]->info,
			NULL,
			&textureMap[path]->d3dTexture
			);
	}

	return textureMap[path];
}
