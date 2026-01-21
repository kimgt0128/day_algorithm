#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	vector<string> alp = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (string target : alp) {
		size_t pos = str.find(target);
		while (pos != string::npos) {
			str.replace(pos, target.size(), "#");
			pos = str.find(target);
		}
	}

	cout << str.size();
	return 0;
}