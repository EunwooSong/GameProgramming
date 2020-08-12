#pragma once
#include "Define.h"
#include <d3dx9.h>

class InputManager
{
private:
	bool beforeKeys[256];
	bool currentKeys[256];

public:
	InputManager();
	~InputManager();

	void UpdateKeyState();
	int GetKeyState(int vk);
	Vec2 GetMousePos();
};

