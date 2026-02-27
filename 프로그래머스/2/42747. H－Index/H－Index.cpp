#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = 1; i <= citations.size(); i++) {
        
        // h=i라 가정하고, 조건 판별
        // 인용 횟수가 i번 이상인 논문이 i개인지 확인
        int over_i = 0;
        int under_i = 0;
        for(int j = 0; j < citations.size(); j++) {
            if(citations[j] >= i) over_i++;
            if(citations[j] <= i) under_i++;
        }
        
        cout << i << ", " << over_i << ", " << under_i;
        if(over_i >= i) {
            answer = max(answer, i);
        }
        cout << ", ans: " << answer << "\n";
        

    }
    
    return answer;
}