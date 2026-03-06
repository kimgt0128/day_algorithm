#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph; // {cost, 다음 간선 저장}
vector<bool> visited;


int prime(int start) {
    int mst = 0;
    // 최소 힙!
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
        
        if(visited[cur_node] == true) continue;
        mst += cur_cost;
        visited[cur_node] = true;
        
        for(auto nxt : graph[cur_node]) {
            int nxt_cost = nxt.first;
            int nxt_node = nxt.second;
            
            if(visited[nxt_node] == false) {
                pq.push({nxt_cost, nxt_node});
            }
        }
    }
    
    return mst;
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 초기 배열 세팅
    graph.resize(n);
    visited.resize(n, false);
    
    // 양방향 그래프 간선 연결
    for(auto cost : costs) {
        int u = cost[0];
        int v = cost[1];
        int c = cost[2];
        
        graph[u].push_back({c, v});
        graph[v].push_back({c, u});
    }
    
    answer = prime(0);
    
    
    
    return answer;
}