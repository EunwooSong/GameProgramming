#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	Sprite* background = nullptr;
	Sprite* startButton = nullptr;
	Sprite* exitButton = nullptr;
	Sprite* explainButton = nullptr;
	Sprite* title = nullptr;


	void Render();
	void Update(float dt);
};

