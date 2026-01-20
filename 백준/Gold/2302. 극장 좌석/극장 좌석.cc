#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<int> seat;
vector<int> dp;

void get_fibonacci() {

	dp.resize(41);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	get_fibonacci();

	int pre = 0;
	int ans = 1;

	for (int i = 0; i < m + 1; i++) {
		int vip;
		if (i == m) vip = n + 1;
		else cin >> vip;
		
		int dis = vip - pre - 1;
		ans *= dp[dis];
		pre = vip;
	}

	

	cout << ans;
	return 0;
}