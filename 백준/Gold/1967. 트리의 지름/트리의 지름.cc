#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)


using namespace std;

int n, ans;
vector<vector<pair<int, int>>> graph;

int dfs(int cur) {

	int ret = 0;

	int maxi = 0;
	int sum = 0;
	
	priority_queue<int> pq;
	for (auto nxt : graph[cur]) {
		int nxt_node = nxt.first;
		int nxt_cost = nxt.second;

		int tmp = nxt_cost + dfs(nxt_node);
		pq.push(tmp);
		maxi = max(maxi, tmp);
	}
	for (int i = 0; i < 2; i++) {
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	ans = max(ans, sum);

	return maxi;

}

int main(void) {

	FAST_IO;

	cin >> n;
	graph.resize(n+1);

	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v, c });
	}

	dfs(1);

	cout << ans;
	
	return 0;
}