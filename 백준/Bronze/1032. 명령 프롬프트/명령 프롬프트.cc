#include<iostream>
#include<vector>

using namespace std;

int n;
vector<string> vec;
int main(void) {
	
	cin >> n;
	vec.resize(n);

	for (int i = 0; i < n; i++) cin >> vec[i];

	string cmp = vec[0];

	for (auto s : vec) {
		for (int i= 0; i < s.size(); i++) {
			if (cmp[i] != s[i]) {
				cmp[i] = '?';
			}
		}
	}

	cout << cmp;


}