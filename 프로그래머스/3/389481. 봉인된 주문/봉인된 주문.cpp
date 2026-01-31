#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

// 26의 거듭제곱을 안전하게 계산하기 위한 함수
ll get_pow(int exp) {
    ll res = 1;
    for (int i = 0; i < exp; i++) res *= 26;
    return res;
}

// 문자열을 원래의 순서 번호(1-based)로 변환
ll str_to_num(string str) {
    ll ret = 0;
    int len = str.length();
    
    // 1. 길이가 len보다 짧은 문자열 개수 합산
    for (int i = 1; i < len; i++) {
        ret += get_pow(i);
    }
    
    // 2. 현재 길이 내에서의 위치 계산 (26진법)
    for (int i = 0; i < len; i++) {
        ll p = get_pow(len - 1 - i);
        ret += (str[i] - 'a') * p;
    }
    
    return ret + 1; // 1-based index
}

// 숫자(1-based)를 다시 문자열로 변환
string num_to_str(ll number) {
    int len = 1;
    ll count;
    
    // 1. 숫자가 어느 길이 구간에 속하는지 찾기
    while (true) {
        count = get_pow(len);
        if (number <= count) break;
        number -= count;
        len++;
    }
    
    // 2. 해당 길이 구간에서 number번째 문자열 생성 (0-based로 보정)
    number -= 1; 
    string ret = "";
    for (int i = 0; i < len; i++) {
        ll p = get_pow(len - 1 - i);
        ret += (char)('a' + (number / p));
        number %= p;
    }
    
    return ret;
}

string solution(ll n, vector<string> bans) {
    vector<ll> banned_indices;
    for (const string& s : bans) {
        banned_indices.push_back(str_to_num(s));
    }
    sort(banned_indices.begin(), banned_indices.end());

    // 이분 탐색 범위 설정 (최대 10^15 + 금지어 개수)
    ll low = 1, high = 2e15; // 충분히 큰 값
    ll answer_idx = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        
        // mid 이하의 금지어 개수 카운트
        ll cnt = upper_bound(banned_indices.begin(), banned_indices.end(), mid) - banned_indices.begin();
        
        // 실제 순서 = 원래 번호 - 금지어 개수
        if (mid - cnt >= n) {
            answer_idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return num_to_str(answer_idx);
}