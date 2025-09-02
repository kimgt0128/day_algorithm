#include <string>
#include <vector>
#include<queue>
#include<tuple>
#include<iostream>
#include<algorithm>

using namespace std;

priority_queue<
    pair<int, int> ,
    vector<pair<int, int>>,
    greater<pair<int, int>>
>pq; //<소요 시간, 요청 시각>


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int n = jobs.size();
    // 요청 시간 기준 정렬
    sort(jobs.begin(), jobs.end());


    // 작업 처리
    int total = 0;
    int time = 0;

    while (idx < n || !pq.empty()) {
        // 현재 작업이 끝나기 전에 시작 요청이 들어온 작업 모두 넣기
        while (idx < n && jobs[idx][0] <= time) {
        // 이미 요청 시각, 소요 시간 순으로 정렬되어 있으므로 요청 시각만 보고 바로 넣어도 최소 보장
        int start = jobs[idx][0];
        int take = jobs[idx][1];
            
        pq.push({ take, start });
        idx++;
            
        }

        // 아직 들어온 작업이 없으면 시간 점프
        if (pq.empty()) time = jobs[idx][0];
        // 우선순위 큐에서 작업 처리하기
        else {
            int start = pq.top().second;
            int take = pq.top().first;
            time += take;
            total += (time - start);
            pq.pop();
        }
        
    }
    answer = total / n;
    return answer;
}

