#pragma once
#include "Define.h"

class Car
{
private:
	int speed;
	int gear;
	string color;
	int* p;
	const int MAX_SPEED;

public:
	Car();
	Car(int speed, int gear, string color);
	~Car();

	void init(int speed, int gear, string color);
	int getSpeed();
	void setSpeed(int speed);
	int getGear();
	void setGear(int gear);
	string getColor();
	void setColor(string color);

	void SpeedUp();
	void SpeedDown();

	void show();
};

