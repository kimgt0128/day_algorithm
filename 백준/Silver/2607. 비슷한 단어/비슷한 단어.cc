#include<iostream>
#include<vector>

using namespace std;

int n;
string cmp;
vector<int> cmp_cnt;
vector<int> str_cnt;

int main(void) {

	cin >> n >> cmp;
	cmp_cnt.resize(26);
	str_cnt.resize(26);
	
	for (auto e : cmp) {
		cmp_cnt[e - 'A']++;
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		string str;
		cin >> str;


		str_cnt.assign(26, 0);
		for (auto c : str) {
			str_cnt[c - 'A']++;
		}

		int common_cnt = 0;
		for (int i = 0; i < 26; i++) {
			common_cnt += min(str_cnt[i], cmp_cnt[i]);
		}

		// 구성이 같은 경우
		if (common_cnt == str.length() && str.length() == cmp.length()) ans++;
		else if (common_cnt == str.length() - 1 && str.length() == cmp.length() + 1) ans++;
		else if (common_cnt == cmp.length() - 1 && str.length() == cmp.length() - 1) ans++;
		else if (common_cnt == cmp.length() - 1 && str.length() == cmp.length()) ans++;
	}


	cout << ans;


}