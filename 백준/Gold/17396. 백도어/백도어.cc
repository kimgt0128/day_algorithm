#include<iostream>
#include<vector>
#include<queue>

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define INF 0x7fffffffffffffff
#define F first
#define S second

using namespace std;

priority_queue < pair<long long, int>, 
	vector<pair<long long, int>>, 
	greater<pair<long long, int>>
> pq;

vector<vector<pair<long long, int>>> graph;
int n, m;

bool sight[100000];

long long dist[100000];

long long dijkstra(int start) {
	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		pair<long long, int> top = pq.top();
		pq.pop();

		int cur = top.S;
		long long cur_cost = top.F;
		
		if (cur == n - 1) return cur_cost;
		if (dist[cur] != cur_cost) continue;

		for (auto e : graph[cur]) {
			int nxt = e.S;
			long long nxt_cost = e.F;

			if (nxt < n-1 && sight[nxt]) continue;

			if (dist[cur] + nxt_cost < dist[nxt]) {
				dist[nxt] = dist[cur] + nxt_cost;
				pq.push({ dist[cur] + nxt_cost, nxt });
			}
		}
	}

	return -1;
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	graph.resize(n);
	for (int i = 0; i < n; i++) dist[i] = INF;
	
	for (int i = 0; i < n; i++) cin >> sight[i];

	for (int i = 0; i < m; i++) {
		long long u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ c, v });
		graph[v].push_back({ c, u });
	}


	cout << dijkstra(0);

	return 0;
}


