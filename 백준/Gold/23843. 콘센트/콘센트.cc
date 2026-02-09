#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> devices;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	FAST_IO;

	cin >> n >> m;
	devices.resize(n);

	for (int i = 0; i < n; i++) cin >> devices[i];

	// 역순 정렬: 큰거부터
	sort(devices.rbegin(), devices.rend());

	for (int i = 0; i < n; i++) {
		int cur = devices[i];

		if (pq.size() < m) {
			pq.push(cur);
		}
		else {
			// 가장 빨리 시작하는거 찾기
			int fast_start = pq.top();
			pq.pop();

			pq.push(fast_start + cur);
			
		}

		
	}

	int ans = 0;
	while (!pq.empty()) {
		ans = max(ans, pq.top());
		pq.pop();
	}

	cout << ans;

	return 0;

}