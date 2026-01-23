#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


map<string, double> score = {
	{"A+", 4.5},
	{"A0", 4.0},
	{"B+", 3.5},
	{"B0", 3.0},
	{"C+", 2.5},
	{"C0", 2.0},
	{"D+", 1.5},
	{"D0", 1.0},
	{"F", 0.0}
};

int main(void) {

	FAST_IO;

	double total = 0;
	double total_credit = 0;

	int t = 20;
	while (t--) {
		string line;
		getline(cin, line);

		// 문자열을 stringstream 객체로 변환
		stringstream ss(line);

		string name, grade;
		double credit;

		ss >> name >> credit >> grade;

		if (grade == "P") continue;

		total += score[grade] * credit;
		total_credit += credit;
	
	}
	

	cout << fixed;
	cout.precision(6);

	if (total_credit == 0) cout << 0.0;
	else cout << total / total_credit;

	return 0;

}