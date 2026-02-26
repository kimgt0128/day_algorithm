#include<iostream>
#include<algorithm>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<vector<int>> metrics;
vector<vector<int>> prefix_sum;
vector<int> row;
vector<int> dp;

int main(void) {

	FAST_IO;

	cin >> n >> m;
	metrics.resize(n + 1, vector<int> (m + 1));
	prefix_sum.resize(n + 1, vector<int>(m + 1));
	row.resize(m + 1);
	dp.resize(m + 1);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cin >> metrics[i][j];
			// 누적합 구하기
			prefix_sum[i][j] = prefix_sum[i - 1][j] + metrics[i][j];
		}
	}

	int ans = 0x80000000;

	for (int i = 1; i < n + 1; i++) {
		for (int j = i; j < n + 1; j++) {
			
			dp.assign(m + 1, 0);
			// prefix_sum으로부터 현재 row 정보가져오기
			for (int k = 1; k < m + 1; k++) {
				row[k] = prefix_sum[j][k] - prefix_sum[i - 1][k];
			}

			// 가져온 row로 구간합 최대 구하기
			for (int k = 1; k < m + 1; k++) {
				dp[k] = max(dp[k - 1] + row[k], row[k]);
			}

			int maxi = *max_element(dp.begin() + 1, dp.end());

			ans = max(ans, maxi);
		}
	}
	cout << ans;
	

	
}







