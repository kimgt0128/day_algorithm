#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<tuple>
#include<set>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
vector<long long> solutions;

int main(void) {

	FAST_IO;

	cin >> n;
	solutions.resize(n);

	for (int i = 0; i < n; i++) cin >> solutions[i];

	sort(solutions.begin(), solutions.end());

	tuple<long long, long long, long long> ans;
	long long almost_zero = LONG_MAX;

	for (int i = 0; i < solutions.size(); i++) {
		long long cur = solutions[i];

		int left = i + 1;
		int right = solutions.size() - 1;

		while (left < right) {

			long long cur_sum = solutions[i] + solutions[left] + solutions[right];

			if (abs(cur_sum) < almost_zero) {
				ans = make_tuple(solutions[i], solutions[left], solutions[right]);
				almost_zero = abs(cur_sum);
			}

			if (cur_sum > 0) right--;
			else if (cur_sum < 0) left++;
			else break;
			
		}
	}
	
	cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);

	return 0;
}