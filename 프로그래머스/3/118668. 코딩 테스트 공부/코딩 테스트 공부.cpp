#include<bits/stdc++.h>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    // alp_req, cop_req 최댓값 구하기
    int alp_max = 0;
    int cop_max = 0;
    
    for(auto p : problems) {
        alp_max = max(alp_max, p[0]);
        cop_max = max(cop_max, p[1]);
    }
    alp = min(alp_max, alp);
    cop = min(cop_max, cop);

    
    vector<vector<int>> dp;
    dp.resize(alp_max + 1, vector<int>(cop_max + 1, 1e9));
    
    
    
    dp[alp][cop] = 0;
    for(int i = alp; i <= alp_max; i++) {
        for(int j = cop; j <= cop_max; j++) {
            
            if(i + 1 <= alp_max) dp[i + 1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if(j + 1 <= cop_max) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);        
            for(int k = 0; k < problems.size(); k++) {
                int alp_req = problems[k][0];
                int cop_req = problems[k][1];
                int alp_rwd = problems[k][2];
                int cop_rwd = problems[k][3];
                int cost = problems[k][4];
                
                // 현재 능력으로 풀 수 있다면?
                if(i >= alp_req && j >= cop_req) {
                    int nxt_alp = min(alp_max, i + alp_rwd);
                    int nxt_cop = min(cop_max, j + cop_rwd);
                    dp[nxt_alp][nxt_cop] = min(dp[nxt_alp][nxt_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    answer = dp[alp_max][cop_max];
    
    return answer;
}