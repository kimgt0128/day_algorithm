#include<bits/stdc++.h>
#define IN(Y, X) (Y >= 0 && Y < n && X >= 0 && X < m)

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dp;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int travel(int y, int x) {
    
    // base condiction
    if(y == n - 1 && x == m - 1) return 1;
    
    // memoizatoin
    int& ret = dp[y][x];
    if(ret != -1) return ret;
    
    // state propagation
    ret = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 내리막 칸이고, 범위 안에 있을 때에만!
        if(IN(ny, nx) && board[ny][nx] < board[y][x]){
            ret += travel(ny, nx);
        }
    }
    return ret;
}


int main(void) {
    
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    dp.resize(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    int answer = travel(0, 0);
    cout << answer;
    
    return 0;
}