#include<bits/stdc++.h>
using namespace std;

vector<string> vowels = {"A", "E", "I", "O", "U"};
string cmp;
int finish, order;

void back_tracking(string cur) {
    // 예외: 크기가 5를 넘어가는 경우
    if(cur.size() > 5) return;

    if(cur != "") order++;
    if(cur == cmp) {
        finish = order;
        return;
    }
    
    // 탐색!
    for(string s : vowels) {
        back_tracking(cur + s);
    }
}

int solution(string word) {
    int answer = 0;
    cmp = word;
    
    back_tracking("");
    
    return answer = finish;
}