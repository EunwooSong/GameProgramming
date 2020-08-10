#pragma once
#include "Define.h"

class Shape
{
protected:
	int x, y;

public :
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}

	virtual void draw() {
		cout << "Shape Draw" << endl;
	}

	virtual void scale() = 0;
};

