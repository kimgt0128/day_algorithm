#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y>=0 && Y<n && X >=0 && X < n)
using namespace std;


int dp[500][500];
int board[500][500];
int ans, n;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int dfs(int y, int x) {
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (IN(ny, nx) && (board[y][x] < board[ny][nx])) {
			if (dp[ny][nx]) dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
			else dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		}
	}
	return dp[y][x];
}

int main(void) {
	FAST_IO;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!dp[i][j]) dp[i][j] = dfs(i, j);
		}
	}

	ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
	
} 