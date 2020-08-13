#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() :currentYPower(0), isGround(false),
gravity(9.81f), jumpCount(2)
{
	Sprite* tmp = new Sprite("Resources/Image/Background.png");
	bgList.push_back(tmp);
	AddObject(tmp);

	tmp = new Sprite("Resources/Image/Background.png");
	bgList.push_back(tmp);
	tmp->setPos(D3DXVECTOR2(tmp->getRect().right, 0));
	AddObject(tmp);


	tmp = new Sprite("Resources/Image/LoopMap.png");
	bridgeList.push_back(tmp);
	tmp->setPos(0, 500);
	AddObject(tmp);

	tmp = new Sprite("Resources/Image/LoopMap.png");
	bridgeList.push_back(tmp);
	tmp->setPos(D3DXVECTOR2(tmp->getRect().right, 500));
	AddObject(tmp);


	player = new Animation(50);
	player->AddFrame("Resources/Image/player-stop.png");
	player->AddFrame("Resources/Image/player-run.png");
	player->setPos(50,100);
	AddObject(player);
}

GameScene::~GameScene()
{
}

void GameScene::Render()
{
	Scene::Render();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	int dir = 500 * dt;
	for (auto bg : bgList) {
		bg->setPos(D3DXVECTOR2(bg->getPosX() - dir, bg->getPosY()));

		if (bg->getPosX() < -bg->getRect().right) {
			bg->setPos(D3DXVECTOR2(bg->getPosX() + bg->getRect().right * 2, bg->getPosY()));
			continue;
		}
	}

	dir = 1000 * dt;
	for (auto bg : bridgeList) {
		bg->setPos(D3DXVECTOR2(bg->getPosX() - dir, bg->getPosY()));

		if (bg->getPosX() < -bg->getRect().right) {
			bg->setPos(D3DXVECTOR2(bg->getPosX() + bg->getRect().right * 2, bg->getPosY()));
			continue;
		}
	}

	PlayerMovement(dt);
}

void GameScene::PlayerMovement(float dt) {
	if (inputManager->GetKeyState(' ') == KEY_DOWN) {
		if (jumpCount > 0) {
			currentYPower += 500;
			isGround = false;
			jumpCount--;
		}
	}
	else if (isGround) {
		jumpCount = 2;
		currentYPower = 0;
	}
	else
		currentYPower -= gravity * 100 * dt;

	player->setPos(player->getPosX(), player->getPosY() - (currentYPower * dt));

	if (player->getPosY() + player->getRect().bottom > 500) {
		player->setPos(player->getPosX(), 500 - player->getRect().bottom);
		isGround = true;
	}
}