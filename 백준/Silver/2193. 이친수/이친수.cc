#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
    
    cin >> n;
    
    long long last_0 = 0;
    long long last_1 = 1;
    
    for(int i = 2; i<n+1; i++) {
        long long cur_0 = last_0 + last_1;
        long long cur_1 = last_0;
        
        last_0 = cur_0;
        last_1 = cur_1;
    }
    
    
    cout << last_0 + last_1;
    
    
}