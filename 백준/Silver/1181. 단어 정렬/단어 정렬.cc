#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n;
vector<string> words;
set<string> s;

bool cmp(string a, string b) {
	if (a.size() < b.size())return true;
	else if (a.size() == b.size()) {
		return a < b;
	}
	else return false;
}

int main(void) {
	
	FAST_IO;

	cin >> n;
	words.resize(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	words = vector<string>(s.begin(), s.end());

	sort(words.begin(), words.end(), cmp);

	for (string s : words) cout << s << "\n";
	return 0;


	
}