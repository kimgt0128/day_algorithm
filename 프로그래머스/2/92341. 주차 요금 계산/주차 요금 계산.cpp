#include <string>
#include <vector>
#include<sstream>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

map<string, int> rec; // 번호, 입차 시각
map<string, int> tim; // 번호, 누적 주차시간 계산
map<string, int> res; // 번호, 주차요금


vector<int> solution(vector<int> fees, vector<string> records) {

    vector<int> answer;

    // 주어진 변수 설정
    int min = fees[0];
    int charge = fees[1];
    int per_min = fees[2];
    int per_charge = fees[3];
    int max_time = 60 * 23 + 59;


    string cur, num, state;
    for (string r : records) {
        istringstream iss(r);
        iss >> cur >> num >> state;

        // 시각 문자열에서 시간, 분 분리하기
        replace(cur.begin(), cur.end(), ':', ' ');
        istringstream t(cur);
        int h, m;
        t >> h >> m; 

        // 입차시 rec에 추가, 출차시 조회 및 저장, 기록 삭제
        if (state == "IN") rec[num] = 60 * h + m;
        else {
            tim[num] += (60 * h + m) - rec[num];
            rec.erase(num);
        }
    }

    // 출차하지 않은 차량들 누적 시간 추가
    while (!rec.empty()) {
        auto it = rec.begin();
        pair<string, int> r = { it->first, it->second };
        string n = r.first;
        int t = r.second;
        rec.erase(it);

        tim[n] += max_time - t;
    }

    // 주차 요금 계산
    for (auto it : tim) {
        string num = it.first;
        int t = it.second;

        res[num] += charge;

        if (t > min) res[num] += ceil((double)(t - min) / per_min) * per_charge;
        
    }
    

    for (auto e : res) cout << e.first << ", " << e.second << endl;
    for (auto it : res) answer.push_back(it.second);

    

    return answer;
}

int main(void) {
    solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
}