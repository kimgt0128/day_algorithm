#include<bits/stdc++.h>

using namespace std;

int m, n, len;
vector<vector<int>> board;

// 회전
vector<vector<int>> rotate(vector<vector<int>>& vec) {
    vector<vector<int>> ret;
    ret.resize(m, vector<int>(m));
    
    for(int i=0; i<m; i++) {
        for(int j = 0; j<m; j++) {
            ret[j][m-1-i] = vec[i][j];
        }
    }
    return ret;
}

// 탐색
bool travel(vector<vector<int>>& key) {

    for(int i=0; i<= len - m; i++) {
        for(int j = 0; j<= len - m; j++) {
            
            // 현재 위치에서 열쇠 채우기!
            for(int k = 0; k < m; k++) {
                for(int l = 0; l < m; l++) {
                    board[k + i][l + j] += key[k][l];
                }
            }
            
            // 검사
            bool flag = true; // 한 번이라도 1이 아니면 false
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    if(board[m-1+k][m-1+l] != 1) {
                        flag = false;
                        break;
                    }
                }
            }
            
            if(flag == true) return true;
            
            // 현재 위치에서 열쇠 되돌리기!
            for(int k = 0; k < m; k++) {
                for(int l = 0; l < m; l++) {
                    board[i+k][j+l] -= key[k][l];
                }
            }  
        }
    }
    
    return false;
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    m = key.size();
    n = lock.size();
    len = n + 2 * m - 2;
    
    board.resize(len, vector<int>(len));
    
    // lock 채우기!
    for(int i =0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            board[i + m - 1][j + m - 1] = lock[i][j];
        }
    }
    
    
    // 4번 돌리면서 탐색하기!
    int rot = 0;
    vector<vector<int>> cur_key = key;
    while(rot < 4) {  
        cur_key = rotate(cur_key);
        bool possible = travel(cur_key);
        
        if(possible) {
            answer = true;
            break;
        }
        
        rot++;
    }
    
    return answer;
}