#include<iostream>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m, ans;
bool error[10];

void travel() {

	for (int i = 0; i < 1000000; i++) {
		string cur = to_string(i);

		bool is_error = false;
		for (auto e : cur) {

			if (error[e - '0']) {
				is_error = true;
				break;
			}
		}
		if (!is_error) {
			ans = min(ans, (int)cur.size() + abs(i - n));
		}
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

	ans = abs(n - 100);
	travel();

	cout << ans;

	return 0;


}
