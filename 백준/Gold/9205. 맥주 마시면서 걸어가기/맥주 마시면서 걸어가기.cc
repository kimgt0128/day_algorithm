#include<bits/stdc++.h>

using namespace std;

bool solve(int n, const vector<pair<int, int>>& nodes) {
    
    vector<bool> visited(n+2, false);
    queue<int> que;
    
    visited[0] = true;
    que.push(0);
    
    int target_y = nodes[n+1].first;
    int target_x = nodes[n+1].second;
    
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        
        int cy = nodes[cur].first;
        int cx = nodes[cur].second;
        
        if(cy == target_y && cx == target_x) return true;
        
        for(int i = 0; i < nodes.size(); i++) {
            int ny = nodes[i].first;
            int nx = nodes[i].second;
            
            if(visited[i] == false && (abs(ny - cy) + abs(nx - cx) <= 1000) ) {
                visited[i] = true;
                que.push(i);
            }
        }
    }
    return false;
}

int main(void) {
    int t, n;
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        vector<pair<int, int>> nodes;
        
        for(int i = 0; i < n + 2; i++) {
            int y, x;
            cin >> y >> x;
            nodes.push_back({y, x});
        }
        bool answer = solve(n, nodes);
        if(answer ==  true) cout << "happy\n";
        else cout << "sad\n";
    }
    
    
    return 0;
}
