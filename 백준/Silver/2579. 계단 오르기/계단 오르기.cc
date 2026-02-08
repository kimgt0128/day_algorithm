#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> stairs;
vector<int> dp;

int main(void) {

	cin >> n;
	stairs.resize(n + 1);
	dp.resize(n + 1);

	for (int i = 1; i < n + 1; i++) {
		cin >> stairs[i];
	}


	dp[1] = stairs[1];
	dp[2] = dp[1] + stairs[2];
	for (int i = 3; i < n + 1; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[n];

	return 0;
}