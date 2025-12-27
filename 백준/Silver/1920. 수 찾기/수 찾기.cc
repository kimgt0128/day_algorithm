#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> vec;


int main(void) {

	FAST_IO;

	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++) cin >> vec[i];

	sort(vec.begin(), vec.end());

	cin >> m;

	while (m--) {

		int target;
		cin >> target;
		bool res = binary_search(vec.begin(), vec.end(), target);
		
		if (res) cout << 1 << "\n";
		else cout << 0 << "\n";

	}
	return 0;
}