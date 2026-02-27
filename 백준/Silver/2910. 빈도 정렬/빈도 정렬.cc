#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<tuple>

using namespace std;

int n, c;
vector<int> nums;
map<int, int> cnt;
map<int, int> first_idx;

int main(void) {

	cin >> n >> c;
	nums.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		cnt[nums[i]]++;
		if (first_idx.find(nums[i]) == first_idx.end()) first_idx[nums[i]] = i;
	}

	sort(nums.begin(), nums.end(), [](int& a, int& b) {
		return make_tuple(cnt[a], -first_idx[a]) > make_tuple(cnt[b], -first_idx[b]);
		});

	for (auto e : nums) cout << e << " ";
}