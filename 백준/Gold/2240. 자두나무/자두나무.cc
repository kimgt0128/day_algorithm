#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int T, W;
int dp[1001][31];
int fruit[1001];
int ans;


int main(void) {
	FAST_IO;

	cin >> T >> W;

	for (int i = 1; i < T+1; i++) {
		cin >> fruit[i];
	}

	for (int i = 1; i < T+1; i++) {
		for (int j = 0; j < W+1; j++) {
			int pos = j % 2 ? 2 : 1; // W개수 홀수이면 pos = 1, 홀수이면 pose = 2

			if (j == 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

			if (pos == fruit[i]) dp[i][j]++;
		}
	}

	for (int i = 0; i < W + 1; i++) ans = max(ans, dp[T][i]);

	cout << ans;


}