#include<bits/stdc++.h>
using namespace std;

int dis[50004];
vector<vector<pair<int, int>>> graph;
set<int> smts;
set<int> gats;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> intensity;
vector<int> ans(2, 0x7fffffff);


void dijkstra() {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 출발 게이트 모두 우선순위 큐에 추가
    for (auto it : gats) {
        dis[it] = 0;
        pq.push({ 0, it });
    }


    while (!pq.empty()) {

        pair<int, int> cur = pq.top();
        int cur_node = cur.second;
        int cur_cost = cur.first;
        pq.pop();
        
        if (cur_cost != dis[cur_node]) continue;

        for (pair<int, int> nxt : graph[cur_node]) {
            int nxt_node = nxt.second;
            int nxt_cost = nxt.first;
            if (gats.find(nxt_node) != gats.end()) continue;

            nxt_cost = max(nxt_cost, dis[cur_node]);
            if (dis[nxt_node] != -1 && nxt_cost >= dis[nxt_node]) continue;

            // 다음 노드가 봉우리이면 우선순위 큐에 넣지 않고  정답 갱신하기
            if (smts.find(nxt_node) != smts.end()) {
                if (nxt_cost < ans[1]) {
                    ans[0] = nxt_node;
                    ans[1] = nxt_cost;
                }
                else if (nxt_cost == ans[1]) {
                    ans[0] = min(ans[0], nxt_node);
                }
                dis[nxt_node] = nxt_cost;

            }
            // 일반 노드이면 우선순위 큐에 넣고 dis업데이트
            else {
                dis[nxt_node] = nxt_cost;
                pq.push({ dis[nxt_node],  nxt_node });
            }

        }
    }


}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    set<pair<int, int>> result;

  
    graph.assign(n+1, {});

    for (auto e : gates) gats.insert(e);
    for (auto e : summits) smts.insert(e);


    for (auto e : paths) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        // 인접 리스트 방식으로 양방향 노드, 가중치 저장하기
        graph[u].push_back({ w, v });
        graph[v].push_back({ w, u });
    }
    
    memset(dis, -1, sizeof(dis));
    dijkstra();

    return ans;
}


int main(void) {
    vector<vector<int>> paths = { {1, 2, 3}, { 2, 3, 5 }, { 2, 4, 2 }, { 2, 5, 4 }, { 3, 4, 4 }, { 4, 5, 3 }, { 4, 6, 1 }, { 5, 6, 1 } };
    //vector<vector<int>> paths = { {1, 2, 5},{1, 4, 1},{2, 3, 1},{2, 6, 7},{4, 5, 1},{5, 6, 1},{6, 7, 1} };
    vector<int> res = solution(6, paths, { 1,3 }, { 5 });

    cout << res[0] << ", " << res[1];

}

