#include<iostream>
#include<string>
#include<deque>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll N, X; cin >> N >> X;
  string S; cin >> S;
  deque<char> dq; // Rs or Ls that effectively affects X
  ll nU = 0; // number of Us that effectively affects X
  for(int i = S.size()-1; i >= 0; --i){
    if(S[i] == 'U') ++nU;
    else{
      if(nU > 0) --nU; // Rs and Ls having Us befind them are canceled
      else dq.push_front(S[i]);
    }
  }
  rep(i,0,nU)if(X > 1) X /= 2;
  while(!dq.empty()){
    char direct = dq.front(); dq.pop_front();
    if(direct == 'R') X = X*2+1;
    if(direct == 'L') X = X*2;
  }
  cout << X << endl;
  return 0;
}