#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene()
{
	background = new Sprite("Resources/Image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Image/mainname.png");
	AddObject(title);
	title->setPos(275, 0);

	startButton = new Sprite("Resources/Image/in.png");
	AddObject(startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);
	startButton->setCenter();

	exitButton = new Sprite("Resources/Image/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);
	exitButton->setCenter();

	//std::cout << exitButton->getRect().left << std::endl;
	//std::cout << exitButton->getRect().top << std::endl;
	//std::cout << exitButton->getRect().right << std::endl;
	//std::cout << exitButton->getRect().bottom<< std::endl;
}

MainScene::~MainScene()
{
}

void MainScene::Render()
{
	Scene::Render();
}

void MainScene::Update(float dt)
{
	Scene::Update(dt);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
	}

	//std::cout << inputManager->GetMousePos().x << ", ";
	//std::cout << inputManager->GetMousePos().y << std::endl;

	if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
		std::cout << "”î" << std::endl;
	}
}
