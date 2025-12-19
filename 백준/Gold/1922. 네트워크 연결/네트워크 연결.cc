#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
vector<int> par;

int Find(int x) {
	return x == par[x] ? x : par[x] = Find(par[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) par[b] = a;
	else par[a] = b;
}

int kruskal() {

	int mst = 0;
	int cnt = 0;

	for (auto cur : edges) {
		int cost = get<0>(cur);
		int u = get<1>(cur);
		int v = get<2>(cur);

		if (Find(u) == Find(v)) continue;
		Union(u, v);
		cnt++;
		mst += cost;

		if (cnt == n - 1) break;
	}

	return mst;

}

int main(void) {
	FAST_IO;

	cin >> n >> m;

	par.resize(n + 1);
	for (int i = 0; i < n + 1; i++) par[i] = i;
	

	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({c, u, v});
		edges.push_back({c, v, u});
	}

	sort(edges.begin(), edges.end());

	int mst_sum = kruskal();

	cout << mst_sum;

	return 0;

	


}
