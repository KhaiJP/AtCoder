#include<iostream>
#include<string>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll a, b, c; cin >> a >> b >> c;
  ll m = c;
  while(b){
    if(a < c){
      cout << "Yes" << endl;
      return 0;
    }
    c *= m;
    --b;
  }
  cout << "No" << endl;
  return 0; 
}