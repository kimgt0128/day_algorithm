#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < m)

using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int n, m, k;
int board[1001][1001];
int cnt[1001][1001][11];
int bfs(int y, int x) {

	queue<tuple<int, int, int>> que;

	que.push(make_tuple( y, x, 0 ));
	cnt[y][x][0] = 1;

	while (!que.empty()) {

		auto cur = que.front();
		que.pop();

		int cy = get<0>(cur);
		int cx = get<1>(cur);
		int used = get<2>(cur);

		if (cy == n - 1 && cx == m - 1) {
			return cnt[cy][cx][used];
		}



		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (!IN(ny, nx)) continue;

			// 한번도 안부순 경우에만 한번 부수기!
			if (used < k && board[ny][nx] == '1' && cnt[ny][nx][used+1] == 0) {
				que.push({ ny, nx, used + 1 });
				cnt[ny][nx][used + 1] = cnt[cy][cx][used] + 1;
			}

			// used이던 아니던 무조건 다음칸은 이동!
			if (board[ny][nx] == '0' && cnt[ny][nx][used] == 0) {
				que.push({ ny, nx, used });
				cnt[ny][nx][used] = cnt[cy][cx][used] + 1;
			}
		}
	}

	return -1;
}

int main(void) {

	FAST_IO;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j];
		}
	}

	int ans = bfs(0, 0);
	
	cout << ans;

	return 0;
}