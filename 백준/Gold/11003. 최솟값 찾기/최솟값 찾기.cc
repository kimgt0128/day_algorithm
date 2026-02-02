#include<iostream>
#include<vector>
#include<queue>

#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, l;
vector<bool> is_pop;
vector<int> nums;
vector<int> ans;
priority_queue<
	pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>
	> idx_pq, num_pq;



int main(void) {

	FAST_IO;

	cin >> n >> l;
	nums.resize(n);
	is_pop.resize(n);
	ans.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	for (int i = 0; i < n; i++) {
		num_pq.push({ nums[i], i });
		idx_pq.push({ i, nums[i] });

		if (i >= l) {
			int idx = idx_pq.top().first;
			idx_pq.pop();
			is_pop[idx] = true;
		}

		while (is_pop[num_pq.top().second]) num_pq.pop();

		ans[i] = num_pq.top().first;
	}

	for (auto e : ans) cout << e << " ";

	return 0;


}