#include<iostream>

using namespace std;

int W[101];
int V[101];
int D[101][100001];

int N, K;

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] > j) D[i][j] = D[i-1][j];
			else D[i][j] = max(D[i-1][j], V[i] + D[i-1][j-W[i]]);
		}
	}
	cout << D[N][K];

	return 0;
}