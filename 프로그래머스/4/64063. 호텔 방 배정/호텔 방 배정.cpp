#include<bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> par;

long long Find(long long x) {
    if(par.find(x) == par.end()) return par[x] = x;
    else return par[x] = Find(par[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    // 방 배정
    for(long long room : room_number) {
        // 가능한 방 찾기
        long long possible = Find(room);
        answer.push_back(possible);
        
        // 두 방 연결
        par[possible] = possible + 1;
        
    }
    
    
    return answer;
}