#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<int> pos;

bool check(int height) {

	int last_covered = 0;

	for (int i = 0; i < m; i++) {
		if (last_covered >= pos[i] - height) {
			last_covered = pos[i] + height;
		}
		else return false;
	}

	return last_covered >= n;
}

int main(void) {

	FAST_IO;

	cin >> n >> m;
	pos.resize(n);

	for (int i = 0; i < m; i++) cin >> pos[i];

	int ans = n;

	int st = 0;
	int en = n;
	while (st <= en) {

		int mid = (st + en) / 2;

		if (check(mid)) {
			en = mid - 1;
			ans = mid;
		} 
		else {
			st = mid + 1;
		}
	}

	cout << ans;

	return 0;
}