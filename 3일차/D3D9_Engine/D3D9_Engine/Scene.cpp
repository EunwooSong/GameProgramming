#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (auto& obj : objList)
		SAFE_DELETE(obj);

	for (auto& ui : uiObjList)
		SAFE_DELETE(ui);
}

void Scene::Render()
{
}

void Scene::Update(float dt)
{
	for (auto& obj : objList)
		obj->Update(dt);
	for (auto& obj : uiObjList)
		obj->Update(dt);
}

void Scene::AddObject(Object* iter)
{
	objList.push_back(iter);
	iter->setParent(nullptr);
}

void Scene::RemoveObject(Object* iter)
{
	objList.remove(iter);
}

void Scene::AddUIObject(Object* iter)
{
	uiObjList.push_back(iter);
	iter->setParent(nullptr);
}

