#include <iostream>
#include <string>

using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;

public:
	void init(int speed, int gear, string color);
	void start();
	void stop();

	int getSpeed();
	void setSpeed(int speed);
	int getGear();
	void setGear(int gear);
	string getColor();
	void setColor(string color);

	void SpeedUp() {
		this->speed += 10;
	}

	void SpeedDown() {
		this->speed -= 10;
	}

	void show() {
		cout << "==========" << endl;
		cout << "속도 : " << speed << endl;
		cout << "기어 : " << gear << endl;
		cout << "색상 : " << color << endl;
		cout << "==========" << endl;
	}
};

int main() {
	Car myCar;
	Car* yourCar = new Car();

	myCar.init(100, 3, "red");
	yourCar->init(10, 1, "blue");

	myCar.SpeedUp();
	yourCar->SpeedUp();

	myCar.show();
	yourCar->show();

	delete yourCar;
	return 0;
}

void Car::init(int speed, int gear, string color)
{
	setColor(color);
	setGear(gear);
	setSpeed(speed);
}

void Car::start()
{
}

void Car::stop()
{
	this->speed = 0;
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
	return this->color;
}

void Car::setColor(string color)
{
	this->color = color
}






