#include<iostream>
#include<vector>
#include<map>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < m)
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int n, m, g, r;
vector<vector<int>> board;
vector<char> picked;
map<char, int> cnt;
vector<pair<int, int>> coors;

int spread() {

	vector<vector<pair<int, char>>> bfs; // 도달 시간, 색깔 담는 bfs 배열
	bfs.assign(n, vector<pair<int, char>>(m, {0, 0}));
	queue<pair<int, int>> que; // 좌표 담는 queue
	int cnt = 0;

	for (int i = 0; i < coors.size(); i++) {
		pair<int, int> coor = coors[i];
		char color = picked[i];
		if (color == 'N') continue;
		// green은 양수, red 는 음수로 시작
		else if (color == 'G') bfs[coor.first][coor.second] = {1, 'G'};
		else bfs[coor.first][coor.second] = {1, 'R'};
		que.push({ coor.first, coor.second });
	}

	// Green, Red를 퍼뜨리며 bfs 진행
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		int cy = cur.first, cx = cur.second;

		if (bfs[cy][cx].second == 'F') continue;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i], nx = cx + dx[i];


			// {ny, nx}가 범위내이고 호수가 아니며 방문 안된 상태이면 방문
			if (IN(ny, nx) && board[ny][nx] != 0) {

				auto nxt = bfs[ny][nx];
				auto now = bfs[cy][cx];

				if (nxt.first == 0) {
					bfs[ny][nx] = { bfs[cy][cx].first + 1, bfs[cy][cx].second};
					que.push({ ny, nx });
				}
				else if (nxt.first == now.first + 1 && nxt.second != 'F' && nxt.second != now.second) {
					bfs[ny][nx].second = 'F';
					cnt++;
				}
			}
			
		}

	}



	return cnt;

}



int get_permutation(int depth) {
	if (depth == coors.size()) {
		return spread();
	}

	int ret = 0;
	for (auto it = cnt.begin(); it != cnt.end(); it = next(it)) {
		pair<int, int> cur = *it;
		char color = it->first;
		int count = it->second;

		if (count > 0) {
			it->second--;
			picked.push_back(color);
			ret = max(ret, get_permutation(depth + 1));
			picked.pop_back();
			it->second++;
		}
	}

	return ret;

}

int main(void) {

	FAST_IO;

	cin >> n >> m >> g >> r;

	board.assign(n, vector<int>(m, 0));
	cnt['G'] = g;
	cnt['R'] = r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) coors.push_back({ i, j });
		}
	}
	cnt['N'] = coors.size() - r - g;

	

	int ans = get_permutation(0);
	cout << ans;

	return 0;

}
