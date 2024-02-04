#include<iostream>
using namespace std;
using ll = int64_t;

ll A, M, L, R, answer;

ll floor(ll x){
  ll r = (x % M + M) % M;
  return (x - r) / M;
}

int main(){
  cin >> A >> M >> L >> R;
  L -= A,  R -= A;
  answer = floor(R) - floor(L-1);
  cout << answer << endl;
  return 0;
}