#include<bits/stdc++.h>

using namespace std;

vector<string> alpha = {"A", "E", "I", "O", "U"};
string cmp;
int order;
int answer = 0;

void travel(int depth, string str) {
    
    
    if(str == cmp) {
        answer = order;
        return;
    }
    
    if(depth == 5) return;
    
    for(int i = 0; i < 5; i++) {
        order++;
        travel(depth + 1, str + alpha[i]);
        if(answer != 0) return;
    }
}

int solution(string word) {

    cmp = word;
    
    travel(0, "");
    
    return answer;
}