#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<long long>> dp;

long long travel(int cur, int num) {

    // base condiction
    if (cur == 1) {
        if(num == 0) return 0;
        if(num == 1) return 1;
    }
    
    // memoization
    long long& ret = dp[cur][num];
    
    if (ret != -1) return ret;
    
    // 상태 전이
    if (num == 0) return ret = travel(cur - 1, 0) + travel(cur - 1, 1);
    else if (num == 1) return ret = travel(cur - 1, 0);
}

int main(void) {
    cin >> n;
    dp.resize(n + 1, vector<long long>(n + 1, -1));
    
    long long answer = travel(n, 0) + travel(n, 1);
    cout << answer;
}