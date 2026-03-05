#include<iostream>
#include<vector>
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < m)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1,0, - 1 };

int n, m;
vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(int cy, int cx) {

	if (cy == n - 1 && cx == m - 1) return 1;

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (IN(ny, nx) && board[ny][nx] < board[cy][cx]) {
			if (dp[ny][nx] == -1) {
				dp[ny][nx] = dfs(ny, nx);
				ret += dp[ny][nx];
			}
			else {
				
				ret += dp[ny][nx];
			}
		}
	}
	
	return dp[cy][cx] = ret;
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	board.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int ans = dfs(0, 0);


	cout << ans;
	

	return 0;
}