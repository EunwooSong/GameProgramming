#pragma once
#include "Scene.h"
#include "GameScene.h"
#include <vector>
#include "Sprite.h"
#include "Animation.h"
#include "Number.h"

class GameScene :
	public Scene
{
private:
	std::vector<Sprite*> bgList;
	std::vector<Sprite*> bridgeList;
	std::vector<Sprite*> obstacleList;
	std::list <Sprite*> coinList;

	Animation* player;
	Number numList[4];

	int score;
	float gravity;
	float currentYPower;
	int jumpCount;
	bool isGround;
	float coinTimer;

public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dt);
	void PlayerMovement(float dt);
};

