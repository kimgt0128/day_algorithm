#include<iostream>
#include<map>
#include<set>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
map<int, int> id; // id, level
set<pair<int, int>> level; // level, id : sorted by {level, id}

int main(void) {

	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int P, L;
		cin >> P >> L;
		id[P] = L;
		level.insert({ L, P });
	}

	cin >> m;

	while (m--) {
		string ord;
		cin >> ord;

		if (ord == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				auto it = level.rbegin();
				cout << it->second << "\n";
			}
			else {
				auto it = level.begin();
				cout << it->second << "\n";
			}

		}

		else if (ord == "add") {
			int p, l;
			cin >> p >> l;
			level.insert({ l, p });
			id[p] = l;
		}
		else {
			int num;
			cin >> num;
			level.erase({id[num], num});
		}
	}
}