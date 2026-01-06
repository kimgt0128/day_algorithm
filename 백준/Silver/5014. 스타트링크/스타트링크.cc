#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int F, S, G, U, D;
vector<bool> visit;


int bfs(int start) {
	queue<pair<int, int>> que;
	
	que.push({start, 0});
	visit[start] = true;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		int cur_floor = cur.first;
		int cur_cnt = cur.second;

		if (cur_floor == G) return cur_cnt;

		for (auto dir : { U, -D }) {
			int nxt_floor = cur_floor + dir;
			if (nxt_floor <= F && nxt_floor > 0 && !visit[nxt_floor]) {

				
				que.push({nxt_floor, cur_cnt + 1});
				visit[nxt_floor] = true;

				//if (nxt_floor == G) return cur_cnt + 1;
			}
		}
	}

	
	return -1;
}

int main(void) {

	FAST_IO;
	cin >> F >> S >> G >> U >> D;

	visit.assign(F + 1, false);

	int ans = bfs(S);
	if (ans == -1) cout << "use the stairs";
	else cout << ans;

	return 0;
}