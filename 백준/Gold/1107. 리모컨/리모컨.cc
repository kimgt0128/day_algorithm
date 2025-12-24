#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

string n;
int m;
bool error[10];
string cur = "";
int ans = 0;

void back_tracking() {

	// base condiction
	if (cur.size() > 6) return;

	if (cur != "") {

		// 방금 추가한 수가 ans 보다 크면 탐색 중지
		int dis = abs(stoi(cur) - stoi(n));
		int int_cur = stoi(cur);
		string str_cur = to_string(int_cur);
		ans = min(ans, (int)str_cur.size() + dis);

	}

	for (int i = 0; i < 10; i++) {
		
		// 현재 추가하려는 숫자가 error이라면 넘기기
		if (error[i]) continue;

		cur.push_back('0' + i);
		back_tracking();
		cur.pop_back();
	}
}


int main(void) {

	FAST_IO;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int inp;
		cin >> inp;
		error[inp] = true;
	}


	ans = abs(stoi(n) - 100);

	back_tracking();

	cout << ans;

	return 0;
}