#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll X, Y, Z, K, A[1010], B[1010], C[1010];
priority_queue< tuple<ll, ll, ll, ll> > q;
set< tuple<ll, ll, ll> > S;

int main(){
  cin >> X >> Y >> Z >> K;
  rep(i, 0, X) cin >> A[i]; sort(A, A+X, greater<ll>());
  rep(i, 0, Y) cin >> B[i]; sort(B, B+Y, greater<ll>());
  rep(i, 0, Z) cin >> C[i]; sort(C, C+Z, greater<ll>());

  q.push({A[0]+B[0]+C[0], 0, 0, 0});
  S.insert({0, 0, 0});
  while(K--){
    ll V, i, j, k;
    tie(V, i, j, k) = q.top();
    cout << V << endl;
    q.pop();
    
    rep(d, 0, 3){
      int x = i + (d == 0), y = j + (d == 1), z = k + (d == 2);
      if(x < X && y < Y && z < Z && S.count({x, y, z}) == 0){
        q.push({A[x] + B[y] + C[z], x, y, z});
        S.insert({x, y, z});
      }
    }
  }

  return 0;
}