#include<iostream>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll X[100010];

int main(){
  ll N, A ,B; cin >> N >> A >> B;
  rep(i, 0, N) cin >> X[i];
  
  ll answer = 0;
  rep(i, 0, N-1) answer += min((X[i+1] - X[i]) * A, B);
  
  cout << answer << endl;
  return 0;
}