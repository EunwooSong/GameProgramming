#include "Point.h"

void Point::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::showPoint()
{
	cout << "(" << x << ", " << y << ")";
}
