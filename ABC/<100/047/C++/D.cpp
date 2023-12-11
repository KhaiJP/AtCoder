#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, T, A[100010], B[100010], minimum, maximum, answer;

int main(){
  cin >> N >> T;
  rep(i, 0, N) cin >> A[i];
  minimum = A[0];

  rep(i, 1, N){
    B[i] = A[i] - minimum;
    minimum = min(minimum, A[i]); 
  }

  rep(i, 1, N) maximum = max(maximum, B[i]);
  rep(i, 0, N) answer += B[i] == maximum;

  cout << answer << endl;
  return 0;
}