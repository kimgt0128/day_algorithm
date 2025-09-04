#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, t;
int dp[10001][10001];


int main(void) {

	FAST_IO;
	cin >> t;

	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j < 4; j++) {
			if (j > i) {
				dp[i][j] = dp[i][j - 1];
				continue;
			}
			for (int k = 1; k <= j; k++) {

				
				if (dp[i - k][k] == 0) dp[i][j] += 1;
				else dp[i][j] += dp[i - k][k];
			}
		}
	}

	while (t--) {
		cin >> n;
		cout << dp[n][3] << "\n";
	}
	return 0;
}