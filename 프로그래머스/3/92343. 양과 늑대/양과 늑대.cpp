#include<bits/stdc++.h>

using namespace std;

vector<int> information;
vector<vector<int>> graph;
int max_sheep = 0;

void travel(int cur, int sheep, int wolf, set<int> next_path) {

    // 양과 늑대 수 갱신
    if (information[cur] == 0) sheep++;
    else wolf++;
    
    // 최댓값 갱신
    max_sheep = max(max_sheep, sheep);
    
    // base condiction
    if(sheep <= wolf) return;
    
    // 자기 자신 노드 제거!
    next_path.erase(cur);
    
    // 현재 노드에서 자식 추가
    for(int nxt : graph[cur]) {
        next_path.insert(nxt);
    }
    
    // 방문
    for(int nxt : next_path) {
        travel(nxt, sheep, wolf, next_path);
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    graph.resize(edges.size() + 1); // 완전 연결 그래프 : 노드수 = 간선수 + 1
    
    information = info;
    // 그래프 관계 세팅
    for(vector<int> e : edges) {
        int u = e[0];
        int v = e[1];
        graph[u].push_back(v);
    }
    
    set<int> nxt_path;
    
    travel(0, 0, 0, {});
    
    return answer = max_sheep;
}