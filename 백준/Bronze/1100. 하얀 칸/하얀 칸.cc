#include<iostream>

using namespace std;

string board[8];

int main(void) {

	for (int i = 0; i < 8; i++) {
		cin >> board[i];
	}

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// 검은 칸!
			if ((i + j) % 2 == 0 && board[i][j] == 'F') {
				cnt++;
			}
		}
	}

	cout << cnt;
		 
}