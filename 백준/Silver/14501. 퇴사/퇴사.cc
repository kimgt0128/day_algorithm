#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> times;
vector<int> pays;
vector<int> dp;



int main(void) {

	cin >> n;
	
	times.resize(n+1);
	pays.resize(n+1);
	dp.resize(n+2);

	for (int i = 1; i < n+1; i++) {
		cin >> times[i] >> pays[i];
	}

	for (int i = n; i > 0; i--) {
		int pass = 0, go = 0;
		if (i + times[i] <= n + 1) go = pays[i] + dp[i + times[i]];
		if (i + 1 <= n+1) pass = dp[i + 1];
		dp[i] = max(go, pass);
	}

	
	
	

	cout << dp[1];

	return 0;

}