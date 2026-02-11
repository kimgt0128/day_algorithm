#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int n;
vector<int> heights;
multiset<int> arrows;

int main(void) {

	cin >> n;
	heights.resize(n);
	
	for (int i = 0; i < n; i++) cin >> heights[i];


	for (int h : heights) {

		auto it = arrows.find(h);
		if (it == arrows.end()) arrows.insert(h - 1);
		else {
			arrows.erase(it);
			arrows.insert(h - 1);
		}


	}

	int ans = arrows.size();

	cout << ans;


}