#pragma once
#include "Object.h"

class Scene
{
private:
	std::list<Object*> objList;
	std::list<Object*> uiObjList;

public:
	Scene();
	~Scene();

	void Render();
	void Update(float dt);

	void AddObject(Object* iter);
	void RemoveObject(Object* iter);
	void AddUIObject(Object* iter);
};

