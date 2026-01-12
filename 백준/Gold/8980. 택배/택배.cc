#include<iostream>
#include<vector>
#include<set>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, c, m;
vector<vector<pair<int, int>>> boxes;
multiset<pair<int, int>> s;

int main(void) {

	FAST_IO;

	cin >> n >> c >> m;
	boxes.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int st, en, cnt;
		cin >> st >> en >> cnt;
		boxes[st].push_back({ en, cnt });
	}

	int cap = 0;
	int ans = 0;

	for (int i = 1; i < n + 1; i++) {

		while (!s.empty() && s.begin()->first == i) {
			auto box = s.begin();
			int wei = box->second;
			ans += wei;
			cap -= wei;
			//현재 box를 set에서 삭제
			auto it = s.find(*box);
			s.erase(it);
		}

		// 일단 넣고
		for (auto box : boxes[i]) {
			s.insert({ box.first, box.second });
			cap += box.second;
		}

		// 넘치면 제일 먼 마을부터 삭제!

		while (cap > c) {
			// set은 어차피 마을 순 오름차순으로 정렬되어 있으므로 맨 뒤에꺼 빼면 알아서 제일 멀리가는 마을 번호의 택배 가져옴!
			int last_weight = s.rbegin()->second;

			if (cap - last_weight >= c) {
				cap -= last_weight;
				s.erase(prev(s.end()));
			}
			else {
				// set의 마지막 값에 접근하여 차이만큼 빼기
				pair<int, int> tmp = *s.rbegin();
				s.erase(tmp);

				tmp.second -= (cap - c);
				cap = c;
				s.insert(tmp);
			}

		}
	}
	cout << ans;

}


