#include<bits/stdc++.h>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    stack<char> sta;
    
    for(auto c : s) {
        if(c == '(') sta.push(c);
        else {
            if(sta.empty()) {
                answer = false;
                break;
            }
            else if (sta.top() == '(') sta.pop();
            else {
                answer = false;
                break;
            }
        }

    }

    if(!sta.empty()) answer = false;
    
    return answer;
}