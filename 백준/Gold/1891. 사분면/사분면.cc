#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

long d, mx, my;
string qstr;
vector<int> new_qnum; // 좌표 -> 사분면 변환 결과
pair<long, long> coor;

// 사분면을 좌표로 변환
pair<long, long> find_coor(int depth, long size, long long x, long long y) {

	// base condiction
	if (depth == d) {
		return coor = { x, y };
	}

	int q = qstr[depth] - '0';
	long half = size >> 1LL;
	// 1사분면이라면
	if (q == 1) {
		return find_coor(depth + 1, half, x + half, y + half);
	}
	// 2사분면이라면
	else if (q == 2) {
		return find_coor(depth + 1, half, x, y + half);
	}
	// 3사분면이라면
	else if (q == 3) {
		return find_coor(depth + 1, half, x, y);
	}
	// 4사분면이라면
	else {
		return find_coor(depth + 1, half, x + half, y);
	}
}

// 좌표를 사분면으로 변환
string find_quard(int depth, long size, long x, long y) {

	if (depth == d) {
		// 문자열 끝은  NULL이어야함
		return "\0";
	}

	long half = size / 2;
	long dx = coor.first - x;
	long dy = coor.second - y;

	if (dx / half == 1 && dy / half == 1) {
		return "1" + find_quard(depth + 1, half, x + half, y + half);
	}
	else if (dx /  half == 0 && dy / half == 1) {
		return "2" + find_quard(depth + 1, half, x, y + half);
	}
	else if (dx / half == 0 && dy / half == 0) {
		return "3" + find_quard(depth + 1, half, x, y);
	}
	else {
		return "4" + find_quard(depth + 1, half, x + half, y);
	}
}


int main(void) {
	
	FAST_IO;

	cin >> d >> qstr >> mx >> my;


	// 자리수만큼 좌표 늘려주기
	long long  max_size = 1LL << d;


	// qnum 의 좌표 알아내기
	coor = find_coor(0, max_size, 0, 0);

	// 좌표 이동
	coor.first += mx;
	coor.second += my;
	

	// 이동한 후 new num의 새로운 사분면 번호 알아내기
	string ans = find_quard(0, max_size, 0, 0);

	if (coor.first < 0 || coor.first >= max_size || coor.second < 0 || coor.second >= max_size) cout << -1;
	else cout << ans;


	return 0;

}