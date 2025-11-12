#include<iostream>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int max_dp[2][3], min_dp[2][3];
int dat[100001][3];
int n;


void solve() {

	int maxi = -1;
	int mini = 0x7fffffff;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				max_dp[1][j]= max(max_dp[0][j], max_dp[0][j + 1]) + dat[i][j];
				min_dp[1][j]= min(min_dp[0][j], min_dp[0][j + 1]) + dat[i][j];
			}
			else if (j == 1) {
				max_dp[1][j] = max({ max_dp[0][j - 1], max_dp[0][j], max_dp[0][j + 1] }) + dat[i][j];
				min_dp[1][j] = min({ min_dp[0][j - 1], min_dp[0][j], min_dp[0][j + 1] }) + dat[i][j];
			}
			else {
				max_dp[1][j] = max(max_dp[0][j - 1], max_dp[0][j]) + dat[i][j];
				min_dp[1][j] = min(min_dp[0][j - 1], min_dp[0][j]) + dat[i][j];
			}
		}

		// 위로 한칸 밀기
		for (int j = 0; j < 3; j++) {
			max_dp[0][j] = max_dp[1][j];
			min_dp[0][j] = min_dp[1][j];
		}
	}

	for (int i = 0; i < 3; i++) maxi = max(maxi, max_dp[0][i]);
	for (int i = 0; i < 3; i++) mini = min(mini, min_dp[0][i]);

	cout << maxi << " " << mini;

}

int main(void) {

	FAST_IO;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dat[i][j];
		}
	}

	solve();

	return 0;
}


