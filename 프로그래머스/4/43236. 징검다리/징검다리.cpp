#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int st = 1;
    int en = distance;
    int mid = 0;
    while (st <= en) {
        mid = (st + en) / 2;
        //cout << mid << endl;
        int pre = 0;
        int cnt = 0;
        for (auto e : rocks) {
            if (e - pre >= mid) pre = e; // 해당 돌 채택 및 갱신
            else cnt++; // 해당 돌 제거
        }
        if (cnt > n) en = mid-1;
        else if (cnt <= n) {
            st = mid + 1;
            answer = mid;
        }
    }
    
    return answer;
}

