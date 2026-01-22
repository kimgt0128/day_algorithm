#include<iostream>
#include<string>
using namespace std;

string str1, str2;

int main(void) {

	cin >> str1 >> str2;

	string s1, s2;

	int mini = 0x7fffffff;

	for (int i = 0; i <= str2.size() - str1.size(); i++) {

		// 최소 다른 부분 찾기
		int cnt = 0;
		for (int j = 0; j < str1.size(); j++) {
			if (str1[j] != str2[j + i]) cnt++;
		}

		mini = min(mini, cnt);
	}

	cout << mini;

	return 0;
}