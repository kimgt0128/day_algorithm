#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<pair<int, int>> items;
priority_queue<
	pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>
> pq;

int main(void) {
	FAST_IO;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		items.push_back({ d, p});
	}

	// day 기준 오름차순 정렬
	sort(items.begin(), items.end());

	for (auto e : items) {
		int d = e.first;
		int p = e.second;

		if (pq.size() < d) {
			pq.push({ p, d });
		}
		else {
			if (pq.top().first < p) {
				pq.pop();
				pq.push({ p, d });
			}
		}
	}

	int ans = 0;


	while (!pq.empty()) {
		ans += pq.top().first;
		pq.pop();
	}

	cout << ans;
	return 0;

}