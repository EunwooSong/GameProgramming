#include "Define.h"
#include "Car.h"
#include "ColorPoint.h"
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"

class A {
public :
	A() { cout << "积己磊 A" << endl; }
	~A() {cout << "家戈磊 A" << endl;}
};

class B : public A{
public :
	B() { cout << "积己磊 B" << endl; }
	~B() { cout << "家戈磊 B" << endl; }
};

class C : public B {
public:
	C() { cout << "积己磊 C" << endl; }
	~C() { cout << "家戈磊 C" << endl; }
};



int main() {
	srand(time(NULL));
	srand(GetTickCount());

	//C c;
	//return 0;

	Shape* s = new Rectangle;

	Rectangle* r = new Rectangle();

	/*Car car1(rand() % 200, 1, "red"), 
		car2(rand() % 200, 1, "blue");
	Car * a = new Car();

	car1.show();
	car2.show();
	
	if (car1.getSpeed() > car2.getSpeed())
		cout << "car1啊 铰府" << endl;
	else if (car1.getSpeed() < car2.getSpeed())
		cout << "car2啊 铰府" << endl;
	else
		cout << "鞍篮 加仿" << endl;

	while (true)
		cout << "ばしば じい 目勘";*/

	//delete a;

	/*Point p;
	ColorPoint cp;
	cp.setPoint(3, 4);
	cp.setColor("red");
	cp.showColorPoint();
	*/
	while (true)
		cout << "ぉしせせ";



	return 0;
}