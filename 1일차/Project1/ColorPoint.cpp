#include "ColorPoint.h"

void ColorPoint::setColor(string color)
{
	this->color = color;
}

void ColorPoint::showColorPoint()
{
	cout << color << " : ";
	showPoint();
}
