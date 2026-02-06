#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int ans = 0x7fffffff;
vector<pair<int, int>> picked;

void get_combination(int depth, int idx) {

	// base condiction
	if (depth == m) {
		// 각 집에서 치킨거리 구하기!
		int chicken_sum = 0;

		for (auto h : houses) {
			// 각 집마다 최솟값 구하기!
			int mini = 0x7fffffff;
			for (auto p : picked) {
				int chicken_dist = abs(h.first - p.first) + abs(h.second - p.second);
				mini = min(mini, chicken_dist);
			}
			chicken_sum += mini;
		}

		// ans 갱신
		ans = min(ans, chicken_sum);
	}

	// index를 돌며 조합 탐색하기!
	for (int i = idx; i < chickens.size(); i++) {
		picked.push_back(chickens[i]);
		get_combination(depth + 1, i + 1);
		picked.pop_back();
	}
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	// 집과 치킨집의 좌푯값 저장!
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int inp;
			cin >> inp;
			if (inp == 1) {
				houses.push_back({ i, j });
			}
			else if (inp == 2) {
				chickens.push_back({ i, j });
			}
		}
	}

	get_combination(0, 0);

	cout << ans;

	return 0;
}