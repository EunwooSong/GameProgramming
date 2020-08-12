#pragma once
#include "Object.h"
#include "Texture.h"

class Sprite :
	public Object
{
private:
	Texture* texture;
	D3DCOLOR color;
	Rect visibleRect;
	int width;
	int height;

public:
	Sprite(char* path);
	~Sprite();

	void Render();

	int getWidth();
	int getHeight();
	D3DCOLOR getColor();

	void setColor(D3DCOLOR color);
	void setCenter();
};

