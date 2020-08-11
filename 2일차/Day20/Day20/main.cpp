//#include <iostream>
//
//using namespace std;
//
//int DividePizza(int, int);
//
//int main() {
//	int pizzaSlices = 0;
//
//	int persons = -1;
//	int slices_per_person = 0;
//
//	try {
//		cout << "���� �������� �Է�";
//		cin >> pizzaSlices;
//		cout << "������� �Է�";
//		cin >> persons;
//
//		if (persons == 0)
//			throw persons;
//
//		slices_per_person = DividePizza(pizzaSlices, persons);
//		cout << "�� ����� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
//	}
//	catch (int e) {
//		cout << "�����" << e << "�� �Դϴ�." << endl;
//	}
//
//	
//	return 0;
//}
//
//int DividePizza(int pizzaSlice, int person) {
//	if (person == 0)
//		throw person;
//
//	return pizzaSlice / person;
//}

//#include <iostream>
//#include "NoPersonException.h"
//using namespace std;
//int main() {
//	int pizzaSlices = 12;
//	int persons = 0;
//	int slicesPerPerson = 0;
//	try {
//		cout << "��� ���� �Է��Ͻÿ�.";
//		cin >> persons;
//		if (persons <= 0) {
//			throw NoPersonException(persons);
//		}
//		slicesPerPerson = pizzaSlices / persons;
//		cout << "�� ����� ���ڴ� " << slicesPerPerson < "�Դϴ�." << endl;
//
//	}
//	catch (NoPersonException e) {
//		cout << "���� : ����� " << e.getPersons() << "�� �Դϴ�." << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

template <class T>
T get_max(T x, T y) {
	return (x > y) ? x : y;
}

template <typename T1, typename T2>
void ShowData(T1 t1, T2 t2) {
	cout << t1 << ", " << t2 << endl;
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << "���� : " << get_max<int>(x, y) << endl;
	cin >> x >> y;
	cout << "�Ǽ� : " << get_max<float>(x, y) << endl;

	cahr c; int a; int b;
	cin >> a >> b >> c;
	ShowData(a, b);
	ShowData(a, c);
	ShowData(c, b);
}