#include<bits/stdc++.h>

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int N, Q;
vector<vector<pair<int, int>>> g;
int dis[5004][5004];
bool visited[5004];

void bfs(int start) {



	queue<int> que;
	que.push(start);
	visited[start] = true;


	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		

		for (pair<int, int> nxt : g[cur]) {
			int nxt_node = nxt.first;
			int nxt_cost = nxt.second;

			if (visited[nxt_node]) continue;
			
			if (dis[start][cur] != 0) {
				nxt_cost = min(nxt_cost, dis[start][cur]);
			}
			dis[start][nxt_node] = nxt_cost;
			visited[nxt_node] = true;
			que.push(nxt_node);
			
		}
	}
}

int main(void) {
	FAST_IO;
	cin >> N >> Q;

	g.resize(N + 1);

	// 양방향 그래프 연결
	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({ u, w });
	}

	// 모든 간선에서 dijkstra 연산

	for (int i = 1; i < N+1; i++) {
		memset(visited, false, sizeof(visited));
		bfs(i);
	}

	while (Q--) {
		int k, v, cnt;
	
		cin >> k >> v;
		cnt = 0;
		for (int i = 1; i < N + 1; i++) {
			if (dis[v][i] >= k) cnt++;
		}
		cout << cnt << "\n";
	}

}