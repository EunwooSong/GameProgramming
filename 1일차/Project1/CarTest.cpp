#include "Define.h"
#include "Car.h"
#include "ColorPoint.h"
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"

class A {
public :
	A() { cout << "������ A" << endl; }
	~A() {cout << "�Ҹ��� A" << endl;}
};

class B : public A{
public :
	B() { cout << "������ B" << endl; }
	~B() { cout << "�Ҹ��� B" << endl; }
};

class C : public B {
public:
	C() { cout << "������ C" << endl; }
	~C() { cout << "�Ҹ��� C" << endl; }
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
		cout << "car1�� �¸�" << endl;
	else if (car1.getSpeed() < car2.getSpeed())
		cout << "car2�� �¸�" << endl;
	else
		cout << "���� �ӷ�" << endl;

	while (true)
		cout << "�Ф��� ���� Ŀ��";*/

	//delete a;

	/*Point p;
	ColorPoint cp;
	cp.setPoint(3, 4);
	cp.setColor("red");
	cp.showColorPoint();
	*/
	while (true)
		cout << "��������";



	return 0;
}