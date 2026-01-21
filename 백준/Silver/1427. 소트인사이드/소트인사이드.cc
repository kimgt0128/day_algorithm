#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {

    string str;
    cin >> str;

    sort(str.rbegin(), str.rend());

    for (auto e : str) cout << e;

    


}