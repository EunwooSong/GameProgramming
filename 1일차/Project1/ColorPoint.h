#pragma once
#include "Point.h"
class ColorPoint :
	public Point
{
private:
	string color;

public:
	void setColor(string color);
	void showColorPoint();
};

