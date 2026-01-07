#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n;
vector<vector<int>> g;
vector<bool> visit;
vector<long> nodes;
vector<long> dp;

long dfs(int cur) {
	visit[cur] = true;

	dp[cur] = 0;
	for (auto nxt : g[cur]) {
		if (visit[nxt]) continue;
		dp[cur] += max((long)0, dfs(nxt));
	}

	return dp[cur] + nodes[cur];

}

int main(void) {
	FAST_IO;

	cin >> n;

	g.resize(n);
	visit.assign(n, false);
	nodes.resize(n);
	dp.resize(n);
	
	for (int i = 0; i < n-1; i++) {
		int p, c;
		cin >> p >> c;
		g[p].push_back(c);
	}

	for (int i = 0; i < n; i++) cin >> nodes[i];

	long ans = dfs(0);
	cout << ans;

	return 0;
}

