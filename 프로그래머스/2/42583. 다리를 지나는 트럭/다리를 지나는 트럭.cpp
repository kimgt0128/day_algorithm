#include<bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    // 초기 변수 세팅
    int t = 0;
    queue<pair<int, int>> que;
    
    // 제일 앞의 트럭 넣기
    int cur_weight = truck_weights[0];
    que.push({1, truck_weights[0]});
    t++;
    int idx = 1;
    
    while(!que.empty()) {
        t++;
        // 먼저 다리에 length만큼 올라와있는 트럭 나가기
        if( t - que.front().first == bridge_length) {
            cur_weight -= que.front().second;
            que.pop();
        }
        
        // 올라갈 수 있으면 타기
        if (idx < truck_weights.size() && cur_weight + truck_weights[idx] <= weight && 
               que.size() < bridge_length) {
            // 현재 들어간 시간 담고, 무게 증가시키기
            que.push({t, truck_weights[idx]});
            cur_weight += truck_weights[idx];
            idx++;
        }   
    }
    
    answer = t;
    return answer;
}