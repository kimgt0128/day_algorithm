#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> nums;
vector<char> opers;

int main(void) {

	string str;
	cin >> str;


	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			opers.push_back(str[i]);
			// 현재 위치를 공백으로 바꾸기!
			str[i] = ' ';
		}
	}

	stringstream ss(str);
	int num;
	while (ss >> num) nums.push_back(num);
	
	
	

	bool flag = false;



	int ans = nums[0];

	for (int i=0; i<opers.size(); i++) {
		
		if (flag == false && opers[i] == '-') {
			flag = true;
		}

		if (flag) ans -= nums[i+1];
		else {
			if (opers[i] == '+') ans += nums[i + 1];
			else ans -= nums[i + 1];
		}
		
	}

	cout << ans;

	return 0;
}