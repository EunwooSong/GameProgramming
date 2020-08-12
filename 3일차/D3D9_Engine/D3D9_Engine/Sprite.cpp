#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(char* path)
{
	texture = textureManager->LoadTextureFromFile(path);

	D3DSURFACE_DESC desc;
	texture->d3dTexture->GetLevelDesc(0, &desc);

	width = desc.Width;
	height = desc.Height;

	rect = visibleRect = Rect(0, 0, width, height);

	color = D3DCOLOR_ARGB(255, 255, 255, 255);
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	Object::Render();

	pd3dSprite->SetTransform(&mat);
	pd3dSprite->Draw(texture->d3dTexture, &visibleRect, NULL, NULL, color);
	
}

int Sprite::getWidth()
{
	return width;
}

int Sprite::getHeight()
{
	return height;
}

D3DCOLOR Sprite::getColor()
{
	return color;
}

void Sprite::setColor(D3DCOLOR color)
{
	color = color;
}

void Sprite::setCenter()
{
	this->pos = -Vec2(width, height) / 2.0f;
	rect = Rect(0, 0, width, height);
	rect.offset(pos);
}
