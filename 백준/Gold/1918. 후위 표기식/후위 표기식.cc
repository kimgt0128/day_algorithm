#include<iostream>
#include<stack>
#include<string>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

string inp;
stack<char> sta;

int main(void) {

	FAST_IO;

	cin >> inp;

	for (int i = 0; i < inp.size(); i++) {

		char s = inp[i];

		if (isalpha(s)) cout << s;
		// 알파벳이 아니면
		else {
			if (s == '(') sta.push('(');
			else if (s == ')') {
				// 닫힌 괄호이면 열린 괄호가 나올 때까지 연산자 출력
				while (sta.top() != '(') {
					cout << sta.top();
					sta.pop();
				}
				// 열린 괄호 제거
				sta.pop();
			} 
			// 연산자이면
			else {
				// 곰셈, 나눗셈이면 자신보다 우선순위가 같은 것들만 제거!
				if (s == '*' || s == '/') {
					while (!sta.empty() && (sta.top() == '*' || sta.top() == '/')) {
						cout << sta.top();
						sta.pop();
					}
					sta.push(s);
				}
				//덧셈,뺄셈이면 자신보다 우선순위가 높은 것들(괄호제외한모든것)을 제거!
				else {
					while (!sta.empty() && sta.top() != '(') {
						cout << sta.top();
						sta.pop();
					}
					sta.push(s);
				}
			}
		}



	}

	while (!sta.empty()) {
		cout << sta.top();
		sta.pop();
	}

	return 0;


}