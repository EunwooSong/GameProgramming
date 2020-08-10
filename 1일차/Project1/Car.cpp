#include "Car.h"

Car::Car() : MAX_SPEED(200)
{ 
	p = new int();
	*p = (int)rand();
	init(0,1,"red");
	cout << "������ ȣ��, " << *p << endl;
}

Car::Car(int speed, int gear, string color)
	:speed(speed), gear(gear), color(color), MAX_SPEED(200)
{
	p = new int();
	*p = (int)rand();
	cout << "������ ȣ��, " << *p << endl;
}

Car::~Car()
{
	cout << "�Ҹ��� ȣ��" << *p << endl;
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
	cout << "�ӵ� : " << speed << endl;
	cout << "��� : " << gear << endl;
	cout << "���� : " << color << endl;
	cout << "==========" << endl;
}