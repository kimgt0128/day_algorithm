#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<string> words;
vector<int> picked;

int main(void) {
	
	FAST_IO;
	cin >> n;
	words.resize(n);

	for (int i = 0; i < n; i++) cin >> words[i];

	// 전처리
	set<char> s;
	map<char, int> m;
	for (string w : words) {
		for (auto c : w) s.insert(c);
	}

	map<char, int> unique_index;
	int idx = 0;
	for (auto e : s) {
		unique_index[e] = idx;
		idx++;
	}



	// 순열 탐색
	vector<int> digit = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int ans = 0;

	do {

		int sum = 0;

		for (string w : words) {
			int word_num = 0;
			int power = 1;
			for (int i = w.size() - 1; i >= 0; i--) {
				word_num += power * digit[unique_index[w[i]]];
				power *= 10;
			}
			sum += word_num;
		}

		ans = max(ans, sum);
		


	} while (next_permutation(digit.begin(), digit.end()));

	cout << ans;
	return 0;
}

