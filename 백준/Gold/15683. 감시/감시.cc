#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < m)

using namespace std;

int n, m, ans;
vector<vector<int>> board;
vector<pair<int, int>> cctvs;
vector<int> direction;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = {1, 0, -1, 0};


void watch(vector<vector<int>>& tmp, int y, int x, int dir) {
	
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	while (IN(ny, nx) && tmp[ny][nx] != 6) {
		if (tmp[ny][nx] == 0) tmp[ny][nx] = 7;
		ny += dy[dir];
		nx += dx[dir];
	}
}

int spy() {
	// 임시 배열 생성
	vector<vector<int>> tmp = board;

	// 각 cctv를 돌면서 방향에 따라 탐색
	for (int i = 0; i < cctvs.size(); i++) {
		int y = cctvs[i].first;
		int x = cctvs[i].second;
		if (tmp[y][x] == 1) {
			watch(tmp, y, x, direction[i]);
		}
		else if (tmp[y][x] == 2) {
			watch(tmp, y, x, direction[i]);
			watch(tmp, y, x, (direction[i] + 2) % 4);

		}

		else if (tmp[y][x] == 3) {
			watch(tmp, y, x, direction[i]);
			watch(tmp, y, x, (direction[i] + 1) % 4);

		}

		else if (tmp[y][x] == 4) {
			watch(tmp, y, x, direction[i]);
			watch(tmp, y, x, (direction[i] + 1) % 4);
			watch(tmp, y, x, (direction[i] + 2) % 4);
		}
		
		else {
			watch(tmp, y, x, direction[i]);
			watch(tmp, y, x, (direction[i] + 1) % 4);
			watch(tmp, y, x, (direction[i] + 2) % 4);
			watch(tmp, y, x, (direction[i] + 3) % 4);
		}
	}


	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void dfs(int depth) {
	
	if (depth == direction.size()) {
		ans = min(ans, spy());
		return;
	}

	for (int i = 0; i < 4; i++) {
		direction[depth] = i;
		dfs(depth + 1);
	}
}

int main(void) {

	FAST_IO;

	cin >> n >> m;
	board.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5){
				cctvs.push_back({ i, j });
			}
		}
	}

	direction.resize(cctvs.size());

	ans = 0x7fffffff;
	dfs(0);

	cout << ans;

	return 0;
}

