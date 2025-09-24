#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
#define F first
#define S second

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;
int dist[1001];
int dp[1001];

void dijkstra(int start) {

	priority_queue<pair<int, int>,
					vector<pair<int, int>>,
					greater<pair<int, int>>> pq;

	pq.push({ 0 ,start });
	dist[start] = 0;

	while (!pq.empty()) {

		pair<int, int> cur = pq.top();
		pq.pop();

		int cur_node = cur.S;
		int cur_dist = cur.F;

		if (cur_dist != dist[cur_node]) continue;

		for (pair<int, int> nxt : g[cur_node]) {
			int nxt_node = nxt.F;
			int nxt_cost = nxt.S;
			if (dist[nxt_node] > dist[cur_node] + nxt_cost) {
				dist[nxt_node] = dist[cur_node] + nxt_cost;
				pq.push({ dist[nxt_node], nxt_node});
			}
		}
	}
}


int back_tracking(int cur, int dis) {
	if (cur == 2) return dp[2];
	if (dp[cur] > 0) return dp[cur];


	for (pair<int, int> nxt : g[cur]) {
		int nxt_node = nxt.F;
		int nxt_cost = nxt.S;


		if (dist[nxt_node] >= dist[cur]) continue;

		dp[cur] += back_tracking(nxt_node, dist[nxt_cost]);


	}
	return dp[cur];
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	g.resize(n + 1);
	fill(dist, dist + n + 1, INF);


	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	dijkstra(2);

	dp[2] = 1;

	back_tracking(1, dist[1]);
	cout << dp[1];

	return 0;


}