#include "stdafx.h"
#include "BitMap.h"
#include "TextureManager.h"

BitMap::BitMap() :
	bits(nullptr), width(0), height(0)
{
}

BitMap::~BitMap()
{
	dispose();
}

void BitMap::init(UINT width, UINT height)
{
	this->width = width;
	this->height = height;

	bits = new bool** [LAYER_COUNT];

	//Create BitMap
	for (int z = 0; z < LAYER_COUNT; z++) {
		bits[z] = new bool* [height];

		for (int y = 0; y < height; y++) {
			bits[z][y] = new bool[width];

			for (int x = 0; x < width; x++)
				bits[z][y][x] = false;
		}
	}
}

void BitMap::dispose()
{
	//Dispose BitMap
	for (int z = 0; z < LAYER_COUNT; z++) {
		for (int y = 0; y < height; y++)
			SAFE_DELETE(bits[z][y]);
		SAFE_DELETE(bits[z]);
	}
}

void BitMap::AddTile(int x, int y, string uri, int layer)
{
	Texture srcTex = *textureManager->LoadTextureFromFile(uri.c_str);

	D3DLOCKED_RECT rect;
	ZeroMemory(&rect, sizeof(rect));
	srcTex.d3dTexture->LockRect(0, &rect, 0, 0);
	const BYTE* pSrcTex = static_cast<BYTE*>(rect.pBits);

	for (int y = 0; y < (int)srcTex.info.Height; y++) {
		for (int x = 0; x < (int)srcTex.info.Width; x++) {
			int index = x * 4 + y * (srcTex.info.Width * 4);
			const BYTE* pSrcColor = &pSrcTex[index];
			BYTE alpha = pSrcColor[3];

			if (alpha == 0xff)
				setBit(x, y, true, layer);
			else
				setBit(x, y, false, layer);
		}
	}
}

void BitMap::setBit(int x, int y, bool b, int layer)
{
	if (x != clamp(x, width, 0)) return;
	if (y != clamp(y, height, 0)) return;

	bits[layer][y][x] = b;
}

bool BitMap::getBit(int x, int y, int layer)
{
	if (x != clamp(x, width, 0)) return false;
	if (y != clamp(y, height, 0)) return false;

	return bits[layer][y][x];
}
