#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;
  rep(i,0,N){
    ll a, b; cin >> a >> b;
    cout << a+b << '\n';
  }
  cout << endl;
  return 0;
}