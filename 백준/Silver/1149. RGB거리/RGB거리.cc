//메모리 절약형: D[2][3]만 사용해서 업데이트할 때마다 D[0]에 밀어넣고 다시D[1]채우기
#include<iostream>
using namespace std;

int H[3];
int D[2][3];
int temp[3];
int N;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) D[0][j] = D[1][j];
		cin >> H[0] >> H[1] >> H[2];
		D[1][0] = H[0] + min(D[0][1], D[0][2]);
		D[1][1] = H[1] + min(D[0][0], D[0][2]);
		D[1][2] = H[2] + min(D[0][0], D[0][1]);
	}
	int ans = 100000;
	for (int i = 0; i < 3; i++) ans = min(ans, D[1][i]);
	cout << ans;

	return 0;
}