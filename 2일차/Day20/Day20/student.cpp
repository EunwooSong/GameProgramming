#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

bool getStu(ifstream&, int&, int&, int&, int&);
void calcGrade(int, int, int, int&, char&);
void writeStu(ofstream&, int, int, char);

int main() {
	ifstream stuFile;
	cout << "프로그램 시작" << endl; 
	stuFile.open("ch7STUFL.DAT");

	if (!stuFile) {
		cerr << "파일 오픈 에러" << endl;
		exit(100);
	}
	ofstream gradesFile;
	gradesFile.open("ch7STUF.DAT");

	if (!gradesFile) {
		cerr << "파일 오픈 에러" << endl;
		exit(100);
	}
	int stuid, exam1, exam2, finalExam, avrg;
	char grade;

	while (getStu(stuFile, stuid, exam1, exam2, finalExam)) {
		calcGrade(exam1, exam2, finalExam, avrg, grade);
		writeStu(gradesFile, stuid, avrg, grade);
	}
	
	stuFile.close();
	gradesFile.close();

	cout << "프로그램 종료" << endl;
	return 0;
}

bool getStu(ifstream& ifs, int& id, int& e1, int& e2, int& fe) {
	ifs >> id >> e1 >> e2 >> fe;
	if (!ifs)
		return false;
	else
		return true;
}

void calcGrade(int e1, int e2, int fe, int& av, char& gr)
{
	av = e1 + e2 + fe; av /= 3.0f;
	if (av >= 90)
		gr = 'A';
	else if (av >= 80)
		gr = 'B';
	else if (av >= 70)
		gr = 'C';
	else if (av >= 60)
		gr = 'D';
	else 
		gr = 'E';
}

void writeStu(ofstream& ofs, int stuID, int avrg, char grade)
{
	ofs.fill('0');
	ofs << setw(4) << stuID;
	ofs.fill(' ');
	ofs << setw(3) << avrg;
	ofs << ' ' << grade << endl;
} 
