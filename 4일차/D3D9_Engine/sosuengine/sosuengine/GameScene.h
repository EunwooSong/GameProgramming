#pragma once
#include "Scene.h"
#include "GameScene.h"
#include <vector>
#include "Sprite.h"
#include "Animation.h"

class GameScene :
	public Scene
{
private:
	std::vector<Sprite*> bgList;
	std::vector<Sprite*> bridgeList;
	Animation* player;
	float gravity;
	float currentYPower;
	int jumpCount;
	bool isGround;

public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dt);
	void PlayerMovement(float dt);
};

