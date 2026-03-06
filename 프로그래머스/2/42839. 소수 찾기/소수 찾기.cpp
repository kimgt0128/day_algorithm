#include<bits/stdc++.h>

using namespace std;

set<int> primes;
vector<bool> visited;

bool is_prime(int num) {
    if (num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void back_tracking(string cur, string& numbers) {
    
    if(cur != "") {
        // 현재 만들어진 숫자가 소수인지 검사
        int to_int = stoi(cur);
        if(is_prime(to_int)) {
            primes.insert(to_int);
        }
    }

    
    
    
    for(int i = 0; i < numbers.size(); i++) {
        if(visited[i] == true) continue;
        visited[i] = true;
        back_tracking(cur + numbers[i], numbers);
        visited[i] = false;
    }
}


int solution(string numbers) { 
    
    int answer = 0;

    int n = numbers.size();
    visited.resize(n);

    back_tracking("", numbers);

    
    return answer = primes.size();
}