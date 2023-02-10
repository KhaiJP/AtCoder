#include<iostream>
#include<string>
#include<utility>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  string S, T; cin >> S >> T;
  rep(i, 0, S.size()-1) if( S[i] != T[i] ){
    swap(S[i], S[i+1]);
    break;
  }
  cout << ( S == T ? yes : noo ) << endl;
  return 0;
}