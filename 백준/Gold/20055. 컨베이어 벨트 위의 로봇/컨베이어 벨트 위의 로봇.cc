#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, k;
vector<pair<int, bool>> belt; // <내구도, 로봇 여부>
int cnt, ans;




int main(void) {

	cin >> n >> k;

	belt.resize(2 * n);

	for (int i = 0; i < n * 2; i++) {
		cin >> belt[i].first;
		if (!belt[i].first) cnt++; // 내구도 0인 칸 미리 관리
	}

	ans = 0;
	
	while (cnt < k) {

		// 벨트 이동
		rotate(belt.begin(), belt.end() - 1, belt.end());

		// 끝에 로봇이 있으면 내리기
		int right = n - 1;
		if (belt[right].second) belt[right].second = false;

		// 로봇 이동
		for (int i = right; i > 0; i--) {
			// 현재 칸에로봇이 없고 전의 칸의 내구도가 존재하고, 다음 칸에 로봇이 없으면 이동
			if (!belt[i].second && belt[i].first && belt[i-1].second) {
				belt[i] = {belt[i].first-1, true}; // 현재 칸의 내구도 감소 후 로봇 이동
				belt[i-1].second = false; // 전의 칸에 로봇 반영
				if (!belt[i].first) cnt++;
			}
		}
		if (belt[right].second) belt[right].second = false;

		// 내구도가 0 이상이면 넣고 감소
		if (belt.begin()->first != 0) {
			belt.begin()->second = true;
			belt.begin()->first--;
			if (!belt.begin()->first) cnt++;
		}

		ans++;
	}

	cout << ans;
	
	

	return 0;

}