#include<bits/stdc++.h>

using namespace std;

int n, cnt, cmp;

void back_tracking(int depth, int cur, const vector<int>& numbers) {
    
    if(depth == n) {
        if(cur == cmp) {
            cnt++;
        }
        return;
    }
    
    back_tracking(depth + 1, cur + numbers[depth], numbers);
    back_tracking(depth + 1, cur - numbers[depth], numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n = numbers.size();
    cmp = target;
    
    back_tracking(0, 0, numbers);
    
    return answer = cnt;
}