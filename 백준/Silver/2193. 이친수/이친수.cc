#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<long long>> dp;

long long travel(int cur, int num) {

    if (cur == 1 && num == 0) {
        return 0;
    }
    if (cur == 1 && num == 1) {
        return 1;
    }

    long long& last_0 = dp[cur - 1][0];
    long long& last_1 = dp[cur - 1][1];

    if (dp[cur][num] == -1) last_0 = travel(cur - 1, 0);
    if (dp[cur][num] == -1) last_1 = travel(cur - 1, 1);

    if (num == 0) {
        return dp[cur][num] = last_0 + last_1;
    }
    if (num == 1) {
        return dp[cur][num] = last_0;
    }
}

int main(void) {
    cin >> n;
    dp.resize(n + 1, vector<long long>(n + 1, -1));
    long long answer = travel(n, 0) + travel(n, 1);

    cout << answer;


}