#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
int max_cnt = 0;

void back_tracking(int cur, int cnt, vector<vector<int>>& dungeons) {
    
    max_cnt = max(max_cnt, cnt);
    
    for(int i = 0; i < dungeons.size(); i++) {
        int a = dungeons[i][0];
        int b = dungeons[i][1];
        
        // 방문 안했고 최소 피로도가 현재 남은 필요도보다 크면 방문
        if(visited[i] == false && cur >= a) {
            visited[i] = true;
            back_tracking(cur - b, cnt + 1, dungeons);
            visited[i] = false;
        }
        
    }   
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    visited.resize(n);
  
    back_tracking(k, 0, dungeons);
    
    
    
    return answer = max_cnt;
}