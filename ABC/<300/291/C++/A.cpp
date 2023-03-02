#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  rep(i, 0, S.size()){
    if((int)(S[i] - 'a') < 0) cout << i+1 << endl;
  }
  return 0;
}