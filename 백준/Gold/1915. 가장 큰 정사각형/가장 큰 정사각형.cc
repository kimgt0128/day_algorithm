#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<vector<int>> dp;
vector<string> board;

int main(void) {
	FAST_IO;

	cin >> n >> m;
	dp.resize(n + 1, vector<int>(m+1, 0));
	board.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int ans = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (board[i - 1][j - 1] == '1') {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans * ans;
	return 0;
	
}