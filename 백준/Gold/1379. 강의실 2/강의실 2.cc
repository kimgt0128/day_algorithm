#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<tuple<int, int, int>> lectures;
priority_queue<
	pair<int, int>, 
	vector<pair<int, int>>, 
	greater<pair<int, int>>
> rooms;

int main(void) {

	FAST_IO;

	cin >> n;
	lectures.resize(n);

	for (int i = 0; i < n; i++) {
		int num, st, en;
		cin >> num >> st >> en;

		lectures[i] = { st, en, num };
	}

	// 끝나는 순으로 정렬!
	sort(lectures.begin(), lectures.end());

	vector<pair<int, int>> res;

	int cnt = 0;
	for (auto lec : lectures) {
		int st = get<0>(lec);
		int en = get<1>(lec);
		int num = get<2>(lec);

		if (rooms.empty()) {
			cnt++;
			rooms.push({ en, cnt });
			res.push_back({ num, cnt });
		}
		else {

			int room_en = rooms.top().first;
			int room_num = rooms.top().second;

			int new_room_num = -1;
			// 기존 강의실에 넣을 수 있으면 기존 번호 넣기!
			if (st >= room_en) {
				rooms.pop();
				new_room_num = room_num;
			}
			else {
				cnt++;
				new_room_num = cnt;
			}

			rooms.push({ en, new_room_num });
			res.push_back({ num, new_room_num });
		}	
	}

	cout << cnt << "\n";

	sort(res.begin(), res.end());
	for (auto r : res) {
		cout << r.second << "\n";
	}
	return 0;
}