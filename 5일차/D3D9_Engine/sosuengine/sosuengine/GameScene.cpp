#include "stdafx.h"
#include "GameScene.h"
#include "MainScene.h"

GameScene::GameScene() :currentYPower(0), isGround(false),
gravity(9.81f), jumpCount(2), score(0), coinTimer(0)
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

	Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH + 70, tmp->getPosY() - 150);
	AddObject(tmpCoin);
	coinList.push_back(tmpCoin);

	Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, tmp->getPosY() - 50);
	AddObject(tmpObstacle);
	obstacleList.push_back(tmpObstacle);

	for (int i = 0; i < 4; i++) {
		numList[i].setPos(D3DXVECTOR2( i * 50, 0));
	}
}

GameScene::~GameScene()
{
}

void GameScene::Render()
{
	Scene::Render();

	for (int i = 0; i < 4; i++) {
		numList[i].Render();
	}
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	int randNum = rand() % 8999 + 1000;

	numList[0].setNum(score / 1000);
	numList[1].setNum(score / 100 % 10);
	numList[2].setNum(score / 10 %10);
	numList[3].setNum(score % 10);

	int dir = 500 * dt;
	for (auto bg : bgList) {
		bg->setPos(D3DXVECTOR2(bg->getPosX() - dir, bg->getPosY()));

		if (bg->getPosX() < -bg->getRect().right) {
			bg->setPos(D3DXVECTOR2(bg->getPosX() + bg->getRect().right * 2, bg->getPosY()));
			continue;
		}
	}

	dir = 750 * dt;
	for (auto bg : bridgeList) {
		bg->setPos(D3DXVECTOR2(bg->getPosX() - dir, bg->getPosY()));

		if (bg->getPosX() < -bg->getRect().right) {
			bg->setPos(D3DXVECTOR2(bg->getPosX() + bg->getRect().right * 2, bg->getPosY()));
			continue;
		}
	}

	for (auto iter : obstacleList) {
		iter->setPos(D3DXVECTOR2(iter->getPosX() - dir, iter->getPosY()));

		if (iter->IsCollisionRect(player)) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}

		if (iter->getPosX() < -iter->getRect().right) {
			iter->setPos(D3DXVECTOR2(iter->getPosX() + SCREEN_WIDTH + iter->getRect().right, iter->getPosY()));

			for (auto i : coinList)
				if (i->IsCollisionRect(iter))
					i->setPos(i->getPos() + D3DXVECTOR2(0, -iter->getRect().bottom - 50));
			continue;
		}
	}

	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		(*iter)->setPos(D3DXVECTOR2((*iter)->getPosX() - dir, (*iter)->getPosY()));
	}

	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if ((*iter)->IsCollisionRect(player)) {
			score += 1;
			RemoveObject(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end())
				break;
		}

		if ((*iter)->getPosX() < -(*iter)->getRect().right) {
			RemoveObject(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end())
				break;
			continue;
		}
	}

	coinTimer += dt;

	if (coinTimer > 0.3f) {
		Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
		tmpCoin->setPos(SCREEN_WIDTH + 70, bridgeList[0]->getPosY() - 50);
		AddObject(tmpCoin);
		coinList.push_back(tmpCoin);

		for (auto obj : obstacleList)
			if (tmpCoin->IsCollisionRect(obj))
				tmpCoin->setPos(tmpCoin->getPos() - D3DXVECTOR2(0, obj->getRect().bottom));

		std::cout << "»ý¼º" << std::endl;
		coinTimer = 0.0f;
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