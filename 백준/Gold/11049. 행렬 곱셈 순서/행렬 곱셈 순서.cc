#include<iostream>
#include<vector>
#include<climits>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<vector<int>> dp;
vector<pair<int, int>> metrics;
vector<int> c;

int solve() {

	dp.assign(n + 1, vector<int>(n + 1, -1));

	for (int i = 0; i < n + 1; i++) dp[i][i] = 0;

	for (int d = 1; d <= n - 1; d++) {

		for (int st = 1; st <= n - d; st++) {
			int en = st + d;
			dp[st][en] = 0x7fffffff;
			for (int mid = st; mid < en; mid++) {
				int cmp = dp[st][mid] + dp[mid + 1][en] + c[st - 1] * c[mid] * c[en];
				dp[st][en] = min(dp[st][en], cmp);
			}
		}

	}

	return dp[1][n];
}

int main(void) {

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		metrics.push_back({ r, c });
	}

	// c 배열로 만들기
	c.push_back(metrics[0].first);
	
	for (auto m : metrics) {
		c.push_back(m.second);
	}

	int ans = solve();
	cout << ans;

	return 0;
}