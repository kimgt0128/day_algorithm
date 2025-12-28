#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;



int n;
vector<int> dat;
vector<int> dp;

int main(void) {

	FAST_IO;

	cin >> n;
	dat.resize(n);
	dp.assign(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> dat[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dat[i] > dat[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = -1;
	for (auto e : dp) ans = max(ans, e);
	cout << ans;



}