#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;

void post_order(int start, int end) {

	if (start == end) {
		cout << tree[start] << "\n";
		return;
	}

	if (start > end) return;

	int root = start;
	int mid = start + 1;
	
	while (mid <= end) {
		if (tree[mid] > tree[start]) break;
		mid++;
	}

	post_order(start + 1, mid - 1);
	post_order(mid, end);
	cout << tree[root] << "\n";
}

int main(void) {

	int cur;
	while (cin >> cur) tree.push_back(cur);

	post_order(0, tree.size() - 1);

	return 0;
}