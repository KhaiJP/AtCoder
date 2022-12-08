#include<iostream>
#include<string>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
    string S, T; cin >> S >> T;
    int i = 0;
    rep(i,T.size()){
        if(i == T.size()-1 || S[i] != T[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
}