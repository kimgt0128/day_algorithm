#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, l;
vector<pair<int, int>> holes;

int main(void) {

	cin >> n >> l;
	holes.resize(n);

	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;

		holes[i] = { st, en };
	}

	sort(holes.begin(), holes.end());

	int ans = 0;
	int last = 0;

	for (auto h : holes) {
		int st = h.first;
		int en = h.second;
		
		if (last < st) {
			int dis = en - st;
			last = st + l * (dis / l);
			ans += dis / l;
			
		}
		else {
			int dis = en - last;
			last = last + l * (dis / l);
			ans += dis / l;
		}

		if (last < en) {
			last += l;
			ans++;
		}
	}

	cout << ans;

	return 0;








}