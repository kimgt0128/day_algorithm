#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<int> nodes;
vector<vector<int>> graph;
vector<vector<int>> dp;

// 인접 노드의 1순위, 2순위 기록
vector<int> max_1;
vector<int> max_2;


int travel(int cur, int from) {
	
	int nxt = (from == max_1[cur] ? max_2[cur] : max_1[cur]);

	if (nxt == -1) return cur;

	int rank = (nxt == max_1[cur] ? 1 : 0);

	if (dp[cur][rank] > 0) return dp[cur][rank];
	else return dp[cur][rank] = travel(nxt, cur);

}

int main(void) {

	FAST_IO;

	cin >> n;
	nodes.resize(n + 1);
	graph.resize(n + 1);
	dp.assign(n + 1, vector<int>(2, 0));

	for (int i = 1; i < n + 1; i++) cin >> nodes[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 각 노드별로 1순위와 2순위 미리 결정
	max_1.resize(n + 1, -1);
	max_2.resize(n + 1, -1);
	for (int i = 1; i < n + 1; i++) {
		priority_queue<pair<int, int>> nxt_nodes;
		for (int j = 0; j < graph[i].size(); j++) {
			int nxt_node = graph[i][j];
			int nxt_val = nodes[nxt_node];
			nxt_nodes.push({ nxt_val, nxt_node });
		}

		max_1[i] = nxt_nodes.top().second, nxt_nodes.pop();
		if(!nxt_nodes.empty()) max_2[i] = nxt_nodes.top().second;
	}

	for (int start = 1; start < n + 1; start++) {
		int end = travel(start, 0);
		cout << end << "\n";
	}

	return 0;
}