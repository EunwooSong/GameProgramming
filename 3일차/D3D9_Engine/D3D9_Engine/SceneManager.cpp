#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager()
	: currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	if(currentScene)
		SAFE_DELETE(currentScene);
}

void SceneManager::Render()
{
	//if (currentScene)
	//	currentScene->Render();
}

void SceneManager::Update(float dTime)
{
	//if (currentScene)
	//	currentScene->Update(dTime);
}

void SceneManager::ChangeScene(Scene* iter)
{
	if (currentScene) SAFE_DELETE(currentScene);
	currentScene = iter;
}
