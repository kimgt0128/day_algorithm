#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> vec;
vector<int> dp;

int main(void) {

	cin >> n;
	vec.resize(n+1);
	dp.resize(n+1, 0);

	for (int i = 1; i < n + 1; i++) cin >> vec[i];

	// dp 계산
	for (int i = 1; i < n + 1; i++) {
		int maxi = vec[i];
		int mini = vec[i];
		for (int j = i-1; j > 0; j--) {
			maxi = max(maxi, vec[j]);
			mini = min(mini, vec[j]);
			
			dp[i] = max(dp[i], dp[j - 1] + maxi - mini);

		}
	}

	cout << dp[n];
}
