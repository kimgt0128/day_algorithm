#include <istream>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<algorithm>

using namespace std;

vector<bool> visited;
//bool visited[50004];
//pair<int, int> dp[50004];
vector<pair<int, int>> dp;
vector<vector<pair<int, int>>> grafh;
set<int> smts;
set<int> gats;


// {cost, node}
pair<int, int> backtracking(pair<int, int> cur) {
    int cur_cost = cur.first;
    int cur_node = cur.second;

    // 봉우리이면 바로 봉우리 반환
    if (smts.find(cur_node) != smts.end()) return { cur_cost, cur_node };

    visited[cur_node] = true;

    int cmp = 0x7fffffff;
    pair<int, int> res;
    for (pair<int, int> nxt : grafh[cur_node]) {

        int nxt_cost = nxt.first;
        int nxt_node = nxt.second;

        // 다음 노드가 시작 노드이면
        if (gats.find(nxt_node) != gats.end()) continue;

        // 다음 노드가 이전 노드라면 넘기기
        if (visited[nxt_node] && dp[nxt_node].second == 0) continue;


        if (visited[nxt_node]) { // 다음 노드가 이미 방문한 기록이 있다면
            res = { dp[nxt_node].first, dp[nxt_node].second };
            res.first = max(nxt_cost, res.first);
        
        }
        else {
            auto it = backtracking(nxt);
            res = { it.first, it.second };
            res.first = max(nxt_cost, res.first);
        }
        //res.first = max(res.first, nxt_cost);
        cmp = min(res.first, cmp);
    }
    
    return dp[cur_node] = { cmp, res.second };
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    visited = vector<bool>(n + 1, false);
    dp = vector<pair<int, int>>(n + 1, { 0, 0 });
    grafh = vector<vector<pair<int, int>>>(n + 1);

    vector<int> ans(2, 0);
    set<pair<int, int>> result;

    for (auto e : gates) gats.insert(e);
    for (auto e : summits) smts.insert(e);


    for (auto e : paths) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        // 인접 리스트 방식으로 양방향 노드, 가중치 저장하기
        grafh[u].push_back({ w, v });
        grafh[v].push_back({ w, u });
    }

    for (int g : gates) result.insert(backtracking({ 0, g }));

    ans = { result.begin()->second, result.begin()->first };
    
    return ans;
}
