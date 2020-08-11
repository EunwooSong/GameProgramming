//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main() {
//	stack<int> s;
//
//	cout << s.empty() << endl;
//
//	s.push(4);
//	s.push(5);
//	s.push(6);
//	cout << s.top() << endl;
//	s.pop();
//	cout << s.top() << endl;
//
//	cout << s.empty() << endl;
//	cout << s.size() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main() {
//	queue<int> q;
//
//	q.push(4);
//	q.push(5);
//	q.push(6);
//	q.pop();
//	cout << q.front() << endl;
//	cout << q.back() << endl;
//	cout << q.empty() << endl;
//	cout << q.size() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	double sum = 0.0;
//
//	const int NUMBER_OF_ENTRIES = 5;
//	vector<double> numbers(NUMBER_OF_ENTRIES);
//
//	for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
//		cin >> numbers[i];
//		sum += numbers[i];
//	}
//
//	cout << "평균 : ";
//
//	for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
//		cout << numbers[i] << ", ";
//	}
//
//	cout << numbers[NUMBER_OF_ENTRIES - 1];
//	cout << sum / NUMBER_OF_ENTRIES;
//
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	vector<double> vec(10);
//
//	cout << "10개의 숫자를 입력해주세요 : ";
//	for (double& elem : vec)
//		cin >> elem;
//
//	for (double elem : vec)
//		cout << elem << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	const int SIZE = 3; 
//	vector<int> a{ 1,2,3 };
//	cout << "벡터 : ";
//
//	for (int i = 0; i < SIZE; i++)
//		cout << a.at(i) << " ";
//
//	cout << endl;
//
//	a[1] = 37;
//
//	for (int i = 0; i < SIZE; i++)
//		cout << a[i] << " ";
//	cout << endl;
//
//	vector<int> v(10);
//	vector<int> v1(10, 1);
//	
//	for (int i : v)
//		cout << i <<  ' ';
//	cout << endl;
//
//	for (int i : v1)
//		cout << i << ' ';
//	cout << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void print(const vector<int>& v) {
//	for (unsigned i = 0; i < v.size(); i++)
//		cout << v[i] << ' ';
//
//	cout << endl;
//}
//
//int main() {
//	vector<int> v{ 10,20,30 };
//	print(v);
//
//	v.at(1) = 200;
//	print(v);
//
//	v.push_back(400);
//	print(v);
//
//
//	v.pop_back();
//	print(v);
//
//	for (int& elem : v) {
//		cout << "입력 : "; cin >> elem;
//	}
//	cout << endl << "[백터] : " << endl;
//	print(v);
//	
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <iomanip>
//using namespace std;
//using Matrix = vector<vector<int>>;
//
//void print(const Matrix& mat);
//
//int main() {
//	Matrix mat{ {1,2,3}, {4,5,6} };
//
//	mat[0][0] = 1;
//	mat[0][1] = 2;
//	mat[0][2] = 3;
//	mat[1][0] = 4;
//	mat[1][1] = 5;
//	mat[1][2] = 6;
//
//	print(mat);
//
//	return 0;
//}
//
//void print(const Matrix& mat)
//{
//	for (unsigned row = 0; row < mat.size(); row++) {
//		for (unsigned col = 0; col < mat[row].size(); col++)
//			cout << setw(4) << mat[row][col];
//		cout << endl;
//	}
//	cout << endl;
//
//	for (const vector<int>& row : mat) {
//		for (int col : row)
//			cout << setw(4) << col;
//		cout << endl;
//	}
//	cout << endl;
//
//
//	for (auto row : mat) {
//		for (auto col : row)
//			cout << setw(4) << col;
//		cout << endl;
//	}
//	cout << endl;
//}


//#include <iostream>
//#include <list>
//
//using namespace std;
//
//bool predicate(int num) {
//	return num >= 37 && num < 100;
//}
//
//int main() {
//	list <int> it;
//
//	for (int i = 0; i < 20; i++)
//		it.push_back(rand() % 200 + 1);
//
//	list<int>::iterator iter;
//
//	cout << "출력 : ";
//
//	for (iter = it.begin(); iter != it.end(); iter++) {
//		cout << *iter << " ";
//	}
//	cout << endl;
//
//	it.remove(10);
//
//	for (int& i : it)
//		cout << i << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main() {
//	bool done = false;
//	char command;
//	int value;
//	list<int> commandList;
//
//	while (!done) {
//		cout << "I) insert P) print L) length E)erase Q)quit >> ";
//		cin >> command;
//
//		switch (command)
//		{
//		case 'I':
//		case 'i':
//			if (cin >> value)
//				commandList.push_back(value);
//			else
//				done = true;
//			break;
//
//		case 'P':
//		case 'p':
//			for (auto elem : commandList)
//				cout << elem << ' ';
//			cout << endl;
//			break;
//
//		case 'L':
//		case 'l':
//			cout << "Number of Elements : " << commandList.size() << endl;
//			break;
//
//		case 'E':
//		case 'e':
//			commandList.clear();
//			break;
//
//		case 'Q':
//		case 'q':
//			done = true;
//			break;
//
//		default:
//			done = true;
//			break;
//		}
//	}
//
//	return 0;
//}

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int>m;
	m.insert(pair<string, int>("abc", 4));
	m.insert(make_pair("ab", 5));

	cout << m.size() << endl;

	m.erase("abc");

	cout << "abc : " << m.count("abc") << endl;
	cout << "ab : " << m.count("ab") << endl;

	for (auto it = m.begin(); it != m.end(); it++)
		cout << "Key : " << it->first << ", Value : " << it->second << endl;
	
	m.clear();
	cout << m.empty();
	return 0;
}
