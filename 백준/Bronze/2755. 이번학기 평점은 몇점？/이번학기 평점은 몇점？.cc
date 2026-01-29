#include<iostream>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

map<string, double> list;




int main(void) {

	list["A+"] = 4.3;
	list["A0"] = 4.0;
	list["A-"] = 3.7;
	list["B+"] = 3.3;
	list["B0"] = 3.0;
	list["B-"] = 2.7;
	list["C+"] = 2.3;
	list["C0"] = 2.0;
	list["C-"] = 1.7;
	list["D+"] = 1.3;
	list["D0"] = 1.0;
	list["D-"] = 0.7;
	list["F"] = 0.0;

	int n;
	cin >> n;
	getchar();
	double total_grade = 0;
	double sum = 0;

	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);

		stringstream ss(line);
		string name, grade;
		int score;
		ss >> name >> score >> grade;

		total_grade += score;
		sum += (score * list[grade]);
	}


	cout << fixed;
	cout.precision(2);
	cout << round(100 * sum / total_grade) / 100 ;

	return 0;


}