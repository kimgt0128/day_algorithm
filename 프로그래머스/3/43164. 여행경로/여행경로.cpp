#include <bits/stdc++.h>
using namespace std;

map<string, multiset<string>> grafh;
vector<string> ans;

void dfs(string tmp) {
    //cout << tmp << endl;
    
    while (!grafh[tmp].empty()) {

        auto it = grafh[tmp].begin();
        grafh[tmp].erase(it);



        dfs(*it);
    }
    
    ans.push_back(tmp);

}

vector<string> solution(vector<vector<string>> tickets) {


    for (auto e : tickets) {
        // 단방향 그래프 생성
        string u = e[0];
        string v = e[1];

        grafh[u].insert(v);
    }

    dfs("ICN");

    reverse(ans.begin(), ans.end());
    return ans;
}


