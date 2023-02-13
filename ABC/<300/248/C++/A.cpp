#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool check[10];

int main(){
  string S; cin >> S;
  for(auto c : S) check[c-'0'] = true;
  rep(i,0,10) if(!check[i]) cout << i << endl;
  return 0;
}