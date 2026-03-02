#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<int> cnt;
vector<int> tim;
vector<int> dp;
vector<vector<int>> g;

int main(void) {

	cin >> n;
	cnt.resize(n + 1);
	tim.resize(n + 1);
	dp.resize(n + 1);
	g.resize(n + 1);

	for (int i = 1; i < n + 1; i++) {
		cin >> tim[i] >> cnt[i];

		for (int j = 0; j < cnt[i]; j++) {
			int from;
			cin >> from;
			g[from].push_back(i);
		}
	}

	queue<int> que;
	

	// 개수가 0인 노드 찾기
	for (int i = 1; i < n + 1; i++) {
		if (cnt[i] == 0) {
			que.push(i);
			dp[i] = tim[i];
		}
	}

	// 위상정렬 수행
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (auto nxt : g[cur]) {
			cnt[nxt]--;
			dp[nxt] = max(dp[nxt], dp[cur] + tim[nxt]);
			if (cnt[nxt] == 0) {
				que.push(nxt);
			}
		}
	}
	
	cout << *max_element(dp.begin() + 1, dp.end());

}