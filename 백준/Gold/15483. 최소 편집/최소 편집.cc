#include<bits/stdc++.h>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int dp[1001][1001];

int edit_distance(string s1, string s2) {

	for (int i = 0; i <= s1.size(); i++) dp[i][0] = i;
	for (int j = 0; j <= s2.size(); j++) dp[0][j] = j;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] + 1;

			dp[i][j] = min({ dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1});
		}
	}

	return dp[s1.size()][s2.size()];
}

int main(void) {

	FAST_IO;

	string str1, str2;

	cin >> str1 >> str2;

	cout << edit_distance(str1, str2);

	return 0;
}