#include<bits/stdc++.h>

using namespace std;

pair<string, int> split_string(string s) {
    
    int st = 0, cnt = 0;

    // 숫자 시작 위치 찾기
    while (st < s.size() && !isdigit(s[st])) st++;

    for (int i = st; i < s.size(); i++) {
        if (!isdigit(s[i]) || cnt >= 5) break;
        cnt++;
    }

    string head = s.substr(0, st);
    int number =  stoi(s.substr(st, cnt));
    
    return make_pair(head, number);

}


bool cmp(string a, string b) {
    pair<string, int> s1 = split_string(a);
    pair<string, int> s2 = split_string(b);
    string head1 = s1.first;
    string head2 = s2.first;
    transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
    transform(head2.begin(), head2.end(), head2.begin(), ::tolower);


    if(head1 != head2) return head1 < head2;
    return s1.second < s2.second;
    
}

vector<string> solution(vector<string> files) {

    vector<string> answer;

    stable_sort(files.begin(), files.end(), cmp);

    answer = vector<string>(files.begin(), files.end());
    return answer;
}

int main() {
    vector<string> files = { "foo9.txt", "foo010bar020.zip", "F-15", "foo2.txt" };
    auto res = solution(files);

    for (auto& f : res) cout << f << "\n";
}