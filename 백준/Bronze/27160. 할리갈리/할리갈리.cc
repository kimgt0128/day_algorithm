#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int n;
map<string, int> cards;



int main(void) {

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);

		stringstream ss(str);

		string name;
		int num;

		ss >> name >> num;
		cards[name] += num;

	}

	bool flag = false;
	for (pair<string, int> card : cards) {
		if (card.second == 5) {
			flag = true;
			break;
		}
	}

	if (flag) cout <<"YES";
	else  cout << "NO";
}

