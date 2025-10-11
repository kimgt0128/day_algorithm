#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x7fffffff
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int t, n, m, k;
int dist[1001][1001];
vector<int> rooms;


void floyd() {
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			for(int k=1; k< n+1; k++) {
				if (dist[j][i] == INF || dist[i][k] == INF) continue;
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}
}

int main(void) {
	FAST_IO;

	cin >> t;

	while(t--) {
		cin >> n >> m;

		rooms.clear();
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i == j) dist[i][j] = 0;
				else dist[i][j] = INF;
			}
		}
		
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = w;
			dist[v][u] = w;
		}


		cin >> k;
		for(int i=0; i<k; i++) {
			int pos;
			cin >> pos;
			rooms.push_back(pos);
		}

		floyd();


		int total = 0x7fffffff;
		int ans = 0;
		
		// 최소가 되는 방 번호 구하기
		for (int i = 1; i < n+1; i++) {
			int sum = 0;
			for (int j = 0; j < rooms.size(); j++) {
				int cur = rooms[j];
				sum += dist[i][cur];
			}
			if (total > sum) {
				total = sum;
				ans = i;
			}
		}

		cout << ans << "\n";

	}

	return 0;
}