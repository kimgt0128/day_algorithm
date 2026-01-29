#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> check;

int prime(int start) {
    
    int sum = 0;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
            > pq;
    
    pq.push({0, start});
    
    while(!pq.empty()) {
        
        auto cur = pq.top();
        pq.pop();
        
        int cur_cost = cur.first;
        int cur_node = cur.second;
        
        if(check[cur_node]) continue;
        sum += cur_cost;
        check[cur_node] = true;
        
        for(auto nxt : graph[cur_node]) {
            int nxt_node = nxt.second;
            int nxt_cost = nxt.first;
            
            if(!check[nxt_node]) {
                pq.push({nxt_cost, nxt_node});
            }
        }
        
    }
    return sum;

}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    graph.resize(n+1);
    check.resize(n+1, false);
    
    for(auto cost : costs) {
        int u, v, c;
        u = cost[0];
        v = cost[1];
        c = cost[2];
        
        graph[u].push_back({c, v});
        graph[v].push_back({c, u});
    }
    
    answer = prime(0);
    
    
    return answer;
}