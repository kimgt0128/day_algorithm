#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // 증설한 서버를 켜진 시간 순으로 정렬하는 pq
    priority_queue<int, vector<int>, greater<int>> servers; 
    for(int i=0; i<players.size(); i++) {
        int cur = players[i];
        cout << "cur: " << i;
        
        // 증설 시간이 지난 서버 확인하고 끄기!
        while(!servers.empty() && i >= servers.top() + k) {
            servers.pop();
        }
        
        // 현재 필요한 서버 수 확인
        int need = cur / m;
        cout << "need: " << need << ", 현재크기: " << servers.size();
        
        // 감당 가능 사용자수보다 많으면 증설하기!
        while(servers.size() < need){
            servers.push(i);
            answer++;
        }
        cout << "\n";
    }
    
    
    
    
    return answer;
}