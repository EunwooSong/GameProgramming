#include "Car.h"

Car::Car() : MAX_SPEED(200)
{ 
	p = new int();
	*p = (int)rand();
	init(0,1,"red");
	cout << "생성자 호출, " << *p << endl;
}

Car::Car(int speed, int gear, string color)
	:speed(speed), gear(gear), color(color), MAX_SPEED(200)
{
	p = new int();
	*p = (int)rand();
	cout << "생성자 호출, " << *p << endl;
}

Car::~Car()
{
	cout << "소멸자 호출" << *p << endl;
	delete p;
}

void Car::init(int speed, int gear, string color)
{
	this->speed = speed;
	this->gear= gear;
	this->color = color;
}

int Car::getSpeed()
{
	return this->speed;
}

void Car::setSpeed(int speed)
{
	this->speed = speed;
}

int Car::getGear()
{
	return this->gear;
}

void Car::setGear(int gear)
{
	this->gear = gear;
}

string Car::getColor()
{
	return color;
}

void Car::setColor(string color)
{
	this->color = color;
}

void Car::SpeedUp()
{
	speed += 10;
}

void Car::SpeedDown()
{
	speed -= 10;
}

void Car::show()
{
	cout << "==========" << endl;
	cout << "속도 : " << speed << endl;
	cout << "기어 : " << gear << endl;
	cout << "색상 : " << color << endl;
	cout << "==========" << endl;
}