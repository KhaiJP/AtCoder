#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  rep(i, 0, S.size()/2){
    cout << S[2*i+1] << S[2*i];
  }
  cout << endl;
  return 0;
}