#include<iostream>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i = (s); i < (t); i++)
typedef long long ll;

ll pow10(ll n);

int main(){
  ll N; cin >> N;
  vector A(N, vector<ll>(N));
  vector<int> dx = {0,1,1,1,0,-1,-1,-1}, dy = {-1,-1,0,1,1,1,0,-1};
  rep(i,0,N){
    ll tmp; cin >> tmp;
    rep(j,0,N){
      A[i][N-j-1] = tmp%10;
      tmp /= 10;
    }
  }
  ll answer = 0;
  rep(i,0,N)rep(j,0,N)rep(d,0,8){
    ll tmp = 0;
    int _i = i, _j = j;
    rep(k,0,N){
      tmp += pow10(N-k-1)*A[_i][_j];
      _i = (_i + dx[d] + N)%N;
      _j = (_j + dy[d] + N)%N;
    }
    answer = max(answer, tmp);
  }
  cout << answer << endl;
  return 0;
}

ll pow10(ll n){
  ll res = 1;
  for(int i = 0; i < n; i++) res *= (ll)10;
  return res;
}