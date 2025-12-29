#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<int> check;
vector<int> num;
int ans;

void back_tracking(int depth) {
	if (depth == n) {
		bool flag = true;
		for (auto e : num) {
			if (check[e] == 0) flag = false;
		}
		if(flag) ans++;
		return;
	}

	for (int i = 0; i < 10; i++) {

		check[i]++;
		back_tracking(depth + 1);
		check[i]--;
		
	}

	
}

int main(void) {

	FAST_IO;

	cin >> n >> m;

	check.assign(10, 0);

	for (int i = 0; i < m; i++) {
		int inp;
		cin >> inp;
		num.push_back(inp);
	}
	back_tracking(0);

	cout << ans;

}
