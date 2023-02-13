#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll A, B, K; cin >> A >> B >> K;
  int answer = 0;
  while( A < B ){
    ++answer;
    A *= K;
  }
  
  cout << answer << endl;
  return 0;
}