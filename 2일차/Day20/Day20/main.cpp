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
//		cout << "피자 조각수를 입력";
//		cin >> pizzaSlices;
//		cout << "사람수를 입력";
//		cin >> persons;
//
//		if (persons == 0)
//			throw persons;
//
//		slices_per_person = DividePizza(pizzaSlices, persons);
//		cout << "한 사람당 피자는 " << slices_per_person << "입니다." << endl;
//	}
//	catch (int e) {
//		cout << "사람이" << e << "명 입니다." << endl;
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
//		cout << "사람 수를 입력하시오.";
//		cin >> persons;
//		if (persons <= 0) {
//			throw NoPersonException(persons);
//		}
//		slicesPerPerson = pizzaSlices / persons;
//		cout << "한 사람당 피자는 " << slicesPerPerson < "입니다." << endl;
//
//	}
//	catch (NoPersonException e) {
//		cout << "오류 : 사람이 " << e.getPersons() << "명 입니다." << endl;
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
	cout << "정수 : " << get_max<int>(x, y) << endl;
	cin >> x >> y;
	cout << "실수 : " << get_max<float>(x, y) << endl;

	cahr c; int a; int b;
	cin >> a >> b >> c;
	ShowData(a, b);
	ShowData(a, c);
	ShowData(c, b);
}