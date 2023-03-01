#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  string S = "1";
  rep(i, 1, N) S = S + ' ' + to_string(i+1) + ' ' + S;
  cout << S << endl;
  return 0;
}