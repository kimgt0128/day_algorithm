#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> nums;
vector<int> cnt;
int maxi, mini;

void get_permutation(int depth, int result) {

	if (depth == n - 1) {
		maxi = max(maxi, result);
		mini = min(mini, result);
	}

	for (int i = 0; i < 4; i++) {
		if (cnt[i] > 0) {
			cnt[i]--;
			if (i == 0) {
				get_permutation(depth + 1, result + nums[depth + 1]);
			}
			else if (i == 1) {
				get_permutation(depth + 1, result - nums[depth + 1]);

			}
			else if (i == 2) {
				get_permutation(depth + 1, result * nums[depth + 1]);

			}
			else {
				get_permutation(depth + 1, result / nums[depth + 1]);

			}
			cnt[i]++;
		}
	}



}

int main(void) {

	cin >> n;
	nums.resize(n);
	cnt.resize(4);

	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < 4; i++) cin >> cnt[i];

	maxi = 0x80000000;
	mini = 0x7fffffff;

	get_permutation(0, nums[0]);

	cout << maxi << "\n" << mini;
	return 0;



	
}

