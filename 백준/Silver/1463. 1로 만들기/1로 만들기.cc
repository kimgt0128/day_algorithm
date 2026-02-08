#include <iostream>

using namespace std;
int N;
int D[1000001];
int main(){
    cin >> N;
    for(int i=2; i<=N; i++){
        D[i] = D[i-1];
        if(i%2==0) D[i] = min(D[i], D[i/2]);
        if(i%3==0) D[i] = min(D[i], D[i/3]);
        D[i] += 1;
    }

    cout << D[N];
   
   return 0;
}