#include<iostream>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
string str,target;

int main(void) {
	FAST_IO;

	cin >> n >> m;
	cin >> str;

	for (int i = 0; i < n; i++) {
		target += "IO";
	}
	target += "I";

	int idx = str.find(target, 0);
	int ans = 0;
	while (idx != string::npos) {
		ans++;
		idx = str.find(target, idx + 2);
	}

	cout << ans;

	return 0;

	
}