#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<tuple>
#include<cctype>
using namespace std;

int n;
vector<string> words;

int digit_sum(string str) {

	int ret = 0;

	for (auto e : str) {
		if (isdigit(e)) ret += (e - '0');
	}
	return ret;
}

int main(void) {

	cin >> n;

	words.resize(n);

	for (int i = 0; i < n; i++) cin >> words[i];

	sort(words.begin(), words.end(), [](string& a, string& b) {
		int sum_a = digit_sum(a);
		int sum_b = digit_sum(b);

		return make_tuple(a.size(), sum_a, a) < make_tuple(b.size(), sum_b, b);
		});

	for (auto e : words) cout << e << "\n";

	return 0;

	


}