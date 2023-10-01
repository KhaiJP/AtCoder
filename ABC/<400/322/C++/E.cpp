#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define chmin(a, b) a = min(a, b)
#define UL (ll)6 * 6 * 6 * 6 * 6 + 10

ll N, K, P, dp[110][UL], C[110], A[110][10], inf = 1e18;

ll encode(vector<ll> &v){
  ll r = 1, val = 0;
  for(auto a : v){
    val += r * a;
    r   *= (P+1);
  }
  return val;
}

vector<ll> decode(ll n){
  vector<ll> r(K);
  rep(i, 0, K){
    r[i] = n % (P+1);
    n /= (P+1);
  }
  return r;
}

int main(){
  cin >> N >> K >> P;
  rep(i, 0, N){
    cin >> C[i];
    rep(k, 0, K) cin >> A[i][k];
  }
  
  rep(i, 0, N+1)rep(j, 0, UL) dp[i][j] = inf;
  dp[0][0] = 0;
  rep(i, 0, N)rep(j, 0, UL)if(dp[i][j] < inf){
    //// not perform i-th idea
    chmin(dp[i+1][j], dp[i][j]);

    //// perform i-th idea
    // current parameters
    vector<ll> v = decode(j);
    // update K parameters
    rep(k, 0, K) v[k] = min(v[k]+A[i][k], P);
    // encode
    ll next_j = encode(v);
    chmin(dp[i+1][next_j], dp[i][j] + C[i]);
  }

  vector<ll> target(K, P);
  ll target_j = encode(target);
  cout << (dp[N][target_j] < inf ? dp[N][target_j] : -1) << endl;
  return 0;
}