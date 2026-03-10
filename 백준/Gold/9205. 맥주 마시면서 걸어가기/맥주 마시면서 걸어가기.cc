#include<bits/stdc++.h>

using namespace std;

int t, n;

bool bfs(int y, int x, int ty, int tx, const vector<pair<int, int>>& nodes) {
    set<pair<int, int>> visited;
    queue<pair<int, int>> que;
    
    visited.insert({y, x});
    que.push({y, x});
    
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        
        int cy = cur.first;
        int cx = cur.second;
        
        // 도착지이면 끝!
        if(cy == ty && cx == tx) return true;
        
        for(auto node : nodes) {
            int ny = node.first;
            int nx = node.second;
            
            // 방문 안했고, 거리가 1000 이하이면 방문!
            if(visited.find({ny, nx}) == visited.end() && abs(ny - cy) + abs(nx - cx) <= 1000) {
                que.push({ny, nx});
                visited.insert({ny, nx});
            }
        }
    }
    
    // 도착 안하고 bfs가 끝나면 fasle
    return false;
}

int main(void) {
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        vector<pair<int, int>> nodes;
        
        for(int i = 0; i < n + 2; i++) {
            int y, x;
            cin >> y >> x;
            nodes.push_back({y, x});
        }
        // 시작, 끝 값 세팅 후 bfs 인자에 넣기!
        int start_y, start_x, target_y, target_x;
        start_y = nodes[0].first;
        start_x = nodes[0].second;
        target_y = nodes[n+1].first;
        target_x = nodes[n+1].second;
        
        bool possible = bfs(start_y, start_x, target_y, target_x, nodes);
        if(possible == true) cout << "happy\n";
        else cout << "sad\n";
    }
    
    
    return 0;
}
