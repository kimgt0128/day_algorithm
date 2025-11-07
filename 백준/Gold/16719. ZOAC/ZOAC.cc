#include<iostream>
#include<map>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

string str;
int visit[101];

void back_tracking(int start, int end) {

	if (start == end) return;

	// 사전순 알파벳 찾기
	int idx = 10000;
	int mini = 'Z+1';
	for (int i = start; i < end; i++) {
		if (!visit[i] && str[i] < mini) {
			idx = i;
			mini = min(mini, (int)str[i]);
		}

	}

	visit[idx] = true;


	// 출력
	for (int i = 0; i < str.size(); i++) {
		if (visit[i]) cout << str[i];
	}
	cout << "\n";

	back_tracking(idx + 1, end);
	back_tracking(start, idx);

}

int main(void) {

	FAST_IO;

	cin >> str;



	back_tracking(0, str.length());


	return 0;
}