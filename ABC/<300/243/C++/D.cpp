#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  ll N, X; cin >> N >> X;
  string S; cin >> S;
  reverse(S.begin(), S.end());

  deque<char> dq; // Rs or Ls that effectively affects X
  ll nU = 0; // number of Us that effectively affects X

  fore(c, S){
    if(c == 'U') ++nU;
    else{
      if(nU > 0) --nU; // Rs and Ls having Us befind them are canceled
      else dq.push_back( c );
    }
  }

  rep(i, 0, nU)if(X > 1) X >>= 1;
  while(!dq.empty()){
    if(dq.back() == 'R') X = X*2+1;
    if(dq.back() == 'L') X = X*2;

    dq.pop_back();
  }

  cout << X << endl;
  return 0;
}