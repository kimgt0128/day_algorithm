#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0
using namespace std;

int n, m;
vector<int> memories;
vector<int> costs;
vector<vector<int>> dp;

int main(void) {
    using namespace std;

    cin >> n >> m;

    memories.resize(n + 1);
    costs.resize(n + 1);

    int max_j = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> memories[i];
    }
    for (int i = 1; i < n + 1; i++) {
        cin >> costs[i];
        max_j += costs[i];
    }
    dp.resize(n + 1, vector<int>(max_j + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < max_j + 1; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - costs[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - costs[i]] + memories[i]);
            }
        }
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < max_j + 1; i++) {
        if (dp[n][i] >= m) ans = min(ans, i);
    }
    cout << ans;

}