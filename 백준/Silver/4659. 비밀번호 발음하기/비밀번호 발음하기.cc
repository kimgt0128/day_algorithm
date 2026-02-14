#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

bool check(string str) {

	// 자음 하나라도 포함
	if (str.find_first_of("aeiou") == string::npos) return false;

	// 자음, 모음 연속 3개인지
	if (str.size() >= 3) {
		for (int i = 2; i < str.size(); i++) {

			if (is_vowel(str[i])) {
				if (is_vowel(str[i - 1]) and is_vowel(str[i - 2])) return false;
			}


			if (!is_vowel(str[i])) {
				if (!is_vowel(str[i - 1]) and !is_vowel(str[i - 2])) return false;
			}
		}
	}

	// aa oo를 제외한 글자 연속 2개인지
	auto it = adjacent_find(str.begin(), str.end());
	
	while (it != str.end()) {
		if (*it != 'e' and *it != 'o') return false;
		it = adjacent_find(next(it), str.end());
	}

	return true;
}


int main(void) {

	string password;

	while (cin >> password) {

		if (password == "end") break;

		bool is_accepted = check(password);



		if (is_accepted) cout << "<" << password << "> is acceptable.\n";
		else cout << "<" << password << "> is not acceptable.\n";
	}

}