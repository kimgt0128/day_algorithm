#include<bits/stdc++.h>


using namespace std;

vector<int> dist;
vector<vector<int>> graph;

void bfs(int start) {

    queue<int> que;
    que.push(start);
    dist[start] = 0;

    while (!que.empty()) {

        int cur = que.front();
        que.pop();

        for (auto nxt : graph[cur]) {

            if (dist[nxt] == -1) {
                dist[nxt] = true;
                que.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }

        }


    }

}


int solution(int n, vector<vector<int>> edge) {

    dist.resize(n + 1, -1);
    graph.resize(n + 1);

    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        // 양방향 연결
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    // 노드 간 거리 구하기
    bfs(1);

    // 정답 구하기
    int answer = 0;
    priority_queue<int> pq;
    for (auto e : dist) pq.push(e);
    int maxi = *max_element(dist.begin(), dist.end());

    while (pq.top() == maxi) {
        answer++;
        pq.pop();
    }

    return answer;

}