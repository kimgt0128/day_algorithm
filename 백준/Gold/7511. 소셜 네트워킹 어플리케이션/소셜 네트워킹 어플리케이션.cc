#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

vector<int> par;

int Find(int cur) {
	return cur == par[cur] ? cur : par[cur] = Find(par[cur]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	
	if (a < b) par[b] = a;
	else par[a] = b;
}

bool is_union(int a, int b) {
	if (Find(a) == Find(b)) return true;
	else return false;
}

int main(void) {

	FAST_IO;
	
	int t, n, k, m;

	cin >> t;

	for(int i=0; i<t; i++) {
		cin >> n;

		par.resize(n);
		for (int j = 0; j < n; j++) par[j] = j;

		cin >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}

		cin >> m;
		cout << "Scenario " << i + 1 << ":\n";
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			if (Find(a) == Find(b)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
        cout << "\n";

		
	}

}