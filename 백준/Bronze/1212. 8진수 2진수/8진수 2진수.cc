#include<iostream>
#include<string>

using namespace std;

int main(void) {


	string hexa;

	cin >> hexa;

	string ans = "";

	for (auto s : hexa) {

		int cur = s - '0'; // 3

		string tmp = "";

		// 3 -> 11
		while (cur) {

			if (cur % 2 > 0) tmp.push_back('1');
			else tmp.push_back('0');

			cur /= 2;
		}
		
		// 11 ->110
		while (tmp.size() < 3) {
			tmp.push_back('0');
		}

		// ans + 011
		ans += string(tmp.rbegin(), tmp.rend());

	}


	auto it = ans.find_first_of('1');
	if (it != string::npos) {
		cout << ans.substr(it);
	}
	else cout << '0';
}