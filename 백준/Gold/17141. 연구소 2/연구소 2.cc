#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < n)

using namespace std;

int n, m, ans;
int cnt;
vector<vector<int>> board;
vector<vector<int>> tmp_board;
vector<pair<int, int>> virus;


vector<pair<int, int>> comb;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int spread(vector<vector<int>>& tmp) {
	queue<pair<int, int>> que;

	// 생성된 바이러스 좌표 조합을 방문체크하고 
	// que에 넣기!
	for (auto c : comb) {
		que.push(c);
		tmp[c.first][c.second] = 0;
	}

	while (!que.empty()) {
		auto front = que.front();
		que.pop();
		int cy = front.first;
		int cx = front.second;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			// 범위 안이고, 벽이 아니며, 방문 안했으면 방문하기
			if (IN(ny, nx) && board[ny][nx] != 1 && tmp[ny][nx] == -1) {
				tmp[ny][nx] = tmp[cy][cx] + 1;
				que.push({ ny, nx });
			}
		}
	}

	// 최소 퍼진 시간 구하기
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(board[i][j] != 1 && tmp[i][j] == -1) return 0x7fffffff;
			if (tmp[i][j] != -1) {
				maxi = max(maxi, tmp[i][j]);
			}
		}
	}

	return maxi;
}

void get_combination(int depth, int index) {
	if (depth == m) {
		// 바이러스를 퍼뜨리기 위한 임시 벡터
		tmp_board.assign(n, vector<int>(n, -1));

		int tim = spread(tmp_board);		
		ans = min(ans, tim);
		return;
	}

	for (int i = index; i < virus.size(); i++) {
		comb.push_back(virus[i]);
		get_combination(depth + 1, i + 1);
		comb.pop_back();
	}

}


int main(void) {

	FAST_IO;

	cin >> n >> m;
	board.resize(n, vector<int>(n));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i, j });
		}
	}

	ans = 0x7fffffff;

	get_combination(0, 0);

	if (ans == 0x7fffffff) cout << -1;
	else cout << ans;

	

}