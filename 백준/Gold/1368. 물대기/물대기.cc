#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<vector<int>> g;
vector<bool> visit;

int prime(int start) {

	int mst = 0;
	priority_queue<pair<int, int>> pq;
	
	pq.push({ 0, start });

	while (!pq.empty()) {

		auto cur = pq.top();
		pq.pop();

		int cur_cost = -cur.first;
		int cur_node = cur.second;

		if (visit[cur_node]) continue;

		visit[cur_node] = true;
		mst += cur_cost;
		
		for (int nxt = 0; nxt <= n; nxt++) {
			int nxt_cost = g[cur_node][nxt];

			if (visit[nxt]) continue;
			pq.push({ -nxt_cost, nxt });
		}
	}

	return mst;
}



int main(void) {
	FAST_IO;

	cin >> n;

	g.assign(n+1, vector<int>(n+1, 0));
	visit.assign(n + 1, false);

	// super node 연결
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		g[0][i] = c;
		g[i][0] = c;
	}

	// 각 노드 연결
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}


	int ans = prime(0);

	cout << ans;

	return 0;
}