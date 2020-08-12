#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager()
{
	ZeroMemory(currentKeys, sizeof(currentKeys));
	ZeroMemory(beforeKeys, sizeof(beforeKeys));
}

InputManager::~InputManager()
{
}

void InputManager::UpdateKeyState()
{
	for (int i = 0; i < 256; i++) {
		beforeKeys[i] = currentKeys[i];
		currentKeys[i] = GetAsyncKeyState(i) & 0x8000;
	}
}

int InputManager::GetKeyState(int vk)
{
	if (beforeKeys[vk] && currentKeys[vk]) return kEY_ON;
	else if (!beforeKeys[vk] && currentKeys[vk]) return KEY_DOWN;
	else if (beforeKeys[vk] && !currentKeys[vk]) return KEY_UP;
	else return KEY_NONE;
}

Vec2 InputManager::GetMousePos()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	ScreenToClient(hWnd, &cursorPos);

	return Vec2(cursorPos.x, cursorPos.y);
}
