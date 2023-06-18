#include<iostream>
using namespace std;
using ull = uint64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ull u1 = 1;

int main(){
  ull answer = 0;
  rep(i, 0, 64){
    ull a; cin >> a;
    answer += a * (u1 << i);
  }
  cout << answer << endl;

  return 0;
}