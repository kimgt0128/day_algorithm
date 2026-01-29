#include<bits/stdc++.h>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

vector<int> par;

int Find(int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    if(a < b) par[b] = a;
    else par[a] = b;
    
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    par.resize(n+1, 0);
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<n+1; i++) par[i] = i;
    
    for(int i=0; i<costs.size(); i++) {
        int u, v, c;
        
        u = costs[i][0];
        v = costs[i][1];
        c = costs[i][2];
        
        edges.push_back({c, u, v});
    }
    // 간선 기준 정렬
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    for(auto edge : edges) {
        
        int c, u, v;
        c = get<0>(edge);
        u = get<1>(edge);
        v = get<2>(edge);
        
        // 둘이 같은 집합이라면 넘기기
        if(Find(u) == Find(v)) continue;
        Union(u, v);
        cnt++;
        answer += c;
        
        
        if(cnt == n-1) break;
    }    
    
    return answer;
}