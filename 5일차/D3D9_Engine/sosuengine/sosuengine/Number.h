#pragma once
#include "Object.h"
#include "Sprite.h"

class Number :
	public Object
{
private:
	Sprite* num[10];
	int currentNum;
	
public:
	Number();
	~Number();

	void Update(float dt);
	void Render();

	void setNum(int num);
	int getNum();
};

