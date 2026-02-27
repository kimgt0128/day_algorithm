#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(void) {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> scores(n);

		for (int i = 0; i < n; i++) cin >> scores[i];

		// 평균 구하기
		double sum = 0;
		for (auto s : scores) sum += s;

		double average = sum / n;
		double cnt = 0;
		for (int i = 0; i < n; i++) {
			if (scores[i] > average) cnt++;
		}
		double percent = 100 * (cnt / (double)n);

		cout << fixed;
		cout.precision(3);
		cout << round((1000 * percent)) / 1000 << "%\n";
	}
}