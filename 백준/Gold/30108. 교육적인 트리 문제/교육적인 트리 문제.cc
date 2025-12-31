#include<iostream>
#include<vector>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n;
vector<int> par;
vector<long> val;

vector<vector<int>> g;

void solve() {
	int cnt = 0;
	long sum = 0;
	priority_queue<pair<long, int>> pq;
	pq.push({ val[1], 1 });

	while (cnt < n) {

		auto cur = pq.top();
		int cur_node = cur.second;
		long cur_val = cur.first;
		pq.pop();

		sum += cur_val;
		cout << sum << "\n";

		// 현재 선택된 자식 노드들을 모두 큐에 추가!
		for (auto child : g[cur_node]) {
			pq.push({ val[child], child });
		}
		cnt++;
	}

	
}



int main(void) {
	FAST_IO;

	cin >> n;

	par.resize(n+1);
	val.resize(n+1);

	// 1번 정점은 트리의 루트
	for (int i = 2; i < n+1; i++) cin >> par[i];
	for (int i = 1; i < n+1; i++) cin >> val[i];


	g.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		int child = i;
		int parent = par[i];

		// par - > child로 연결 그래프
		g[parent].push_back(i);
	}

	solve();
	
	return 0;

}