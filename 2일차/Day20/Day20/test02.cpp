#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ftxt;
	string s;
	ftxt.open("Day02.txt");

	ftxt >> s;
	cout << s << endl;

	ftxt.close();

	ofstream otxt;

	string str;
	otxt.open("tmp.txt");
	cin >> str;
	otxt << str;
	otxt.close();
}