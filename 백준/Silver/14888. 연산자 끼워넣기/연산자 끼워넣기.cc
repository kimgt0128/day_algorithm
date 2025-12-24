#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<int> nums;
int cnt[4];
int mini = 0x7fffffff; // 01111111111111111111
int maxi = 0x80000000;

vector<int> perm; // 중복순열 저장!

void back_tracking(int depth) {
	if (depth == n-1) {

		// 계산 후 최솟값 비교
		int tmp = nums[0];
		int idx = 0;
		for (int i = 1; i < n; i++) {

			if (perm[idx] == 0) {
				tmp += nums[i];
			}
			else if (perm[idx] == 1) {
				tmp -= nums[i];
			}
			else if (perm[idx] == 2) {
				tmp *= nums[i];
			}
			else {
				if (nums[idx] > 0) {
					tmp /= nums[i];
				}
				else {
					tmp /= -nums[i];
					tmp *= -1;
				}
			}
			idx++;


		}

		maxi = max(maxi, tmp);
		mini = min(mini, tmp);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cnt[i] == 0) continue;
		// cnt가 양수일 때에만 적용

		cnt[i]--;
		perm.push_back(i);
		back_tracking(depth + 1);
		cnt[i]++;
		perm.pop_back();

	}

}

int main(void) {

	FAST_IO;

	cin >> n;

	nums.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> cnt[i];
	}

	// back_tracking
	back_tracking(0);


	cout << maxi << "\n" << mini;




	return 0;
}