#include <string>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;

set<string> s;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (string p : phone_book) {
        string tmp = "";
        for (int i = 0; i < p.size(); i++) {
            tmp.push_back(p[i]);
            if (s.find(tmp) != s.end()) {
                answer = false;
                break;
            }
        }
        s.insert(tmp);
        if (answer == false) break;
    }
    return answer;
}