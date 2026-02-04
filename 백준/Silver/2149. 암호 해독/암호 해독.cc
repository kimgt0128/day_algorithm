#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string key, code;
vector<pair<char, int>> idx;
vector<pair<int, string>> decode;

int main(void) {
	cin >> key >> code;
	int key_len = key.size();
	int col_len = code.size() / key.size();

	idx.resize(key_len);
	

	for (int i = 0; i < key_len; i++) {
		idx[i] = { key[i], i };
	}

	stable_sort(idx.begin(), idx.end());

	decode.resize(key.size());
	for (int i = 0; i < key.size(); i++) {
		decode[i] = { idx[i].second, code.substr(i * col_len, col_len) };
	}
	sort(decode.begin(), decode.end());
	for (int i = 0; i < col_len; i++) {
		for (int j = 0; j < key_len; j++) {
			cout << decode[j].second[i];
		}
	}

}