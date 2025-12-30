#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define FAST_IO

using namespace std;

int n, m;
vector<vector<int>> board;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> comb;


int main(void) {
	
	FAST_IO;

	cin >> n >> m;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i, j });
			if (board[i][j] == 2) chicken.push_back({ i, j });
		}
	}


	comb.assign(chicken.size(), 0);
	for (int i = 0; i < m; i++) comb[i] = 1;
	sort(comb.begin(), comb.end());

	int ans = 0x7ffffff;

	do {
		int sum = 0;
		for (auto h : house) {
			int mini = 0x7fffffff;
			for (int i = 0; i < chicken.size(); i++) {
				if (comb[i] == 0) continue;
				pair<int, int> picked = chicken[i];
				mini = min(mini, abs(h.first - picked.first) + abs(h.second - picked.second));
			}
			sum += mini;

		}

		ans = min(ans, sum);


		

	} while (next_permutation(comb.begin(), comb.end()));
	

	

	cout << ans;

	return 0;
}


