#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    ll a; cin >> a;
    A[i] = a - (i + 1);
  }sort(A, A+N);

  ll mid = A[N/2];
  ll answer = 0;
  rep(i, 0, N) answer += abs(A[i] - mid);
  
  cout << answer << endl;
  return 0;
}