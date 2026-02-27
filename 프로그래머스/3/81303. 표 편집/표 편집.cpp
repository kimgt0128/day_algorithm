#include<bits/stdc++.h>

using namespace std;

stack<int> sta;
vector<pair<int, int>> linked_list;
int cur;

string solution(int n, int k, vector<string> cmd) {
    
    // linked_list 초기 세팅!
    linked_list.resize(n);
    for(int i = 0; i < n; i++) {
        int pre = i - 1;
        int nxt = i + 1;
        
        if(pre < 0) pre = -1;
        if(nxt >= n) nxt = -1;
        
        linked_list[i] = {pre, nxt};
    }
    
    cur = k;
    
    //명령 수행!
    for(string c : cmd) {
        
        // 명령어 실행
        if(c[0] == 'U') {
            string x = c.substr(2);
            for(int i = 0; i < stoi(x); i++) cur = linked_list[cur].first;
        }
        else if(c[0] == 'D') {
            string x = c.substr(2);
            for(int i = 0; i < stoi(x); i++) cur = linked_list[cur].second;
        }
        
        else if(c[0] == 'C') {
            // 삭제한 노드 스택에 넣기
            sta.push(cur);
            
            
            // 이 전 노드가 존재하면
            int pre = linked_list[cur].first;
            int nxt = linked_list[cur].second;
            if(pre != -1) linked_list[pre].second = linked_list[cur].second;
            if(nxt != -1) linked_list[nxt].first = linked_list[cur].first;
            
            if(nxt == -1) cur = pre;
            else cur = nxt;
            
            
        }
        else {
            int target = sta.top();
            sta.pop();
            
            // 복구
            int pre = linked_list[target].first;
            int nxt = linked_list[target].second;
            
            if(nxt != -1) linked_list[nxt].first = target;
            if(pre != -1) linked_list[pre].second = target;
        }
    }
    
    // 삭제되었는지 체크
    string answer(n, 'O');
    while(!sta.empty()) {
        answer[sta.top()] = 'X';
        sta.pop();
    }
    return answer;
}