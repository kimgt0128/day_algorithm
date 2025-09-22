#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int t, n;
vector<string> phones;

int main(void) {

	cin >> t;

	while (t--) {

		cin >> n;
		phones.clear();

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			phones.push_back(str);
		}
		sort(phones.begin(), phones.end());
		
		bool consistency = true;
		for (int i = 0; i < phones.size() - 1; i++) {
			if (phones[i + 1].rfind(phones[i], 0) == 0) {
				consistency = false;
				break;
			}
		}

		if (consistency == true) cout << "YES\n";
		else cout << "NO\n";
	

	}


	return 0;
}