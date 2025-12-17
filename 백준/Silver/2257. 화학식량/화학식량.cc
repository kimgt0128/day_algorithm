#include<iostream>
#include<stack>
#include<string>
#include<map>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

map<char, int> m;



int main(void) {

	FAST_IO;
	
	m['H'] = 1;
	m['C'] = 12;
	m['O'] = 16;
	int ans = 0;
	string str;
	stack<int> sta;

	cin >> str;

	for (auto e : str) {
		if (e == '(') sta.push(0);
		else if (isdigit(e)) {
			int tmp = sta.top();
			sta.pop();
			sta.push(tmp * (e - '0'));
		}
		else if (e == ')') {
			int tmp = 0;
			while (sta.top() != 0) {
				tmp += sta.top();
				sta.pop();
			}
			sta.pop();
			sta.push(tmp);
		}
		else {
			sta.push(m[e]);
		}
	}


	while (!sta.empty()) {
		ans += sta.top();
		sta.pop();
	}
	cout << ans;

	return 0;



}