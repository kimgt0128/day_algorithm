#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> times;
vector<int> pays;
vector<int> dp;




int travel(int cur) {

	if (cur > n) return 0;

	if (dp[cur] > 0) return dp[cur];

	int tmp1 = 0, tmp2 = 0;
	if(cur + times[cur] <= n+1)tmp1 = pays[cur] + travel(cur + times[cur]);
	tmp2 = travel(cur + 1);
	dp[cur] = max(tmp1, tmp2);
	return dp[cur];

}

int main(void) {

	cin >> n;
	
	times.resize(n+1);
	pays.resize(n+1);
	dp.resize(n+1);

	for (int i = 1; i < n+1; i++) {
		cin >> times[i] >> pays[i];
	}

	int ans = 0;
	
	ans = travel(1);

	cout << ans;

	return 0;

}