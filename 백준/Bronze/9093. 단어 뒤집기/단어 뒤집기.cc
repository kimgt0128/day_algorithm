#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


int t;
vector<string> vec;

int main(void) {
	cin >> t;
	getchar();

	while (t--) {
		vec.clear();

		string str;
		getline(cin, str);

		stringstream ss(str);

		string word;
		while (ss >> word) vec.push_back(word);

		for (auto w : vec) {
			for (int i = w.size() - 1; i >= 0; i--) cout << w[i];
			cout << " ";
		}
		cout << "\n";

		



	}


}