#include "stdafx.h"
#include "Animation.h"

Animation::Animation(int fps)
	: fps(fps),
	color(D3DCOLOR_ARGB(255, 255, 255, 255)),
	maxFrame(0),
	currentFrame(0),
	timeChecker(0),
	height(0),
	width(0)
{
}

Animation::~Animation()
{
	for (auto& iter : spriteVector)
		SAFE_DELETE(iter);
}

void Animation::Render()
{
	Object::Render();

	if (maxFrame > 0) {
		spriteVector[currentFrame]->setColor(color);
		spriteVector[currentFrame]->Render();
	}
}

void Animation::Update(float dt)
{
	timeChecker += dt;

	if (timeChecker > 1.0f / fps) {
		timeChecker = 0;
		currentFrame++;

		if (currentFrame == maxFrame) {
			currentFrame = 0;
		}
	}
}

void Animation::AddFrame(char* path)
{
	spriteVector.push_back(new Sprite(path));
	AddChild(spriteVector[maxFrame]);

	if (maxFrame == 0) {
		width = spriteVector[maxFrame]->getWidth();
		height = spriteVector[maxFrame]->getHeight();
	}

	maxFrame++;
}
