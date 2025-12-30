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

int ans = 0x7fffffff;
vector<int> comb;

void get_combination(int depth, int idx) {

	if (depth == m) {


		// 선택된 조합에 대해 치킨거리 구하기
		int sum = 0;
		for (auto h : house) {
			int mini = 0x7ffffff;
			for (auto c : comb) {
				mini = min(mini, abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second));
			}
			sum += mini;
		}

		ans = min(ans, sum);

		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		comb.push_back(i);
		get_combination(depth + 1, i + 1);
		comb.pop_back();
	}

}


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

	get_combination(0, 0);

	cout << ans;

	return 0;
}


