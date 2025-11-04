#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


void bubble_sort(vector<int> arr, int n, int k) {
	int cnt = 0;
	for (int i=0; i < n-1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				cnt++;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				
				if (cnt == k) {
					cout << arr[j] << " " << arr[j + 1];
					return;
				}
			}
		}

	}

	cout << -1;
	return;
}


int main(void) {

	FAST_IO;

	int n, k;
	vector<int> arr;

	cin >> n >> k;
	
	for (int i=0; i < n; i++) {
		int inp;
		cin >> inp;
		arr.push_back(inp);
	}

	bubble_sort(arr, n, k);

	return 0;
}