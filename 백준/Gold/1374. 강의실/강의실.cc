#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<pair<int, int>> lectures;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	FAST_IO;

	cin >> n;
	lectures.resize(n);

	for (int i = 0; i < n; i++) {
		int num, st, en;
		cin >> num >> st >> en;

		lectures[i] = { st, en };
	}

	// 끝나는 순으로 정렬!
	sort(lectures.begin(), lectures.end());

	for (auto lec : lectures) {
		int st = lec.first;
		int en = lec.second;

		pq.push(en);

		if (st >= pq.top()) pq.pop();
	}

	cout << pq.size();
	return 0;
}