#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string a, b, c, d;

	cin >> a >> b >> c >> d;

	string s1 = a + b;
	string s2 = c + d;

	cout << stoll(s1) + stoll(s2);
}