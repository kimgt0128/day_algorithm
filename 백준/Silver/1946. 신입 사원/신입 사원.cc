#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int t;

int main(void) {
	FAST_IO;

	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector<pair<int, int>> scores(n);
		vector<pair<int, int>> ans;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			scores[i] = { a, b };
		}

		sort(scores.begin(), scores.end());

		for (int i = 0; i < n; i++) {
			if (ans.empty()) {
				ans.push_back(scores[i]);
				continue;
			}

			int b = ans.back().second;
			int tmp = scores[i].second;

			if (tmp <= b) {
				ans.push_back(scores[i]);
			}
		}

		cout << ans.size() << "\n";
	}

	return 0;
}