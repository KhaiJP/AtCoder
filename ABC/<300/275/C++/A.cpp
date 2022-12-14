#include<iostream>
#define rep(i,n) for(int i=0; i<=n; ++i)
using namespace std;

int main(){
    int n; cin >>n;
    int ref = 0; int H; int argmx = 0;
    rep(i, n-1){
        cin >> H;
        if(H > ref){
            ref = H;
            argmx = i+1;
        }
    }
    cout << argmx << endl;
    return 0;
}