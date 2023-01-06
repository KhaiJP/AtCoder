#include<iostream>
#include<vector>
#include<set>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
typedef int64_t ll;
typedef pair<ll,ll> pr;
#define rep(i, s, t) for (ll i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;
  ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  vector<pr> centres(N+2);        // centres[i]: centre of circle i
  vector<ll> radius_of(N+2);      // radius_of[i]: radius of circle i
  rep(i,1,N+1){
    ll x, y, r; cin >> x >> y >> r;
    centres[i] = {x,y};
    radius_of[i] = r;
  }
  // take the start point as a circle of which the centre is (sx, sy) and the radius is 0
  centres[0]   = {sx,sy}; radius_of[0]   = 0;
  // take the terminal point as a circle of which the centre is (tx, ty) and the radius is 0
  centres[N+1] = {tx,ty}; radius_of[N+1] = 0;

  dsu uf(N+2); // uf.same(i,j) == true -> circle i and j intresect each other via some some circles.
  rep(i,0,N+2)rep(j,i+1,N+2){
    // center x, y and radius of circle i
    ll &x1 = centres[i].first, &y1 = centres[i].second, &r1 = radius_of[i];
    // center x, y and radius of circle j
    ll &x2 = centres[j].first, &y2 = centres[j].second, &r2 = radius_of[j];
    
    // check if circle i and j intersect
    bool close_enough  = (  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= (r1+r2)*(r1+r2)  );
    bool not_contained = (  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) >= (r1-r2)*(r1-r2)  );
    if( close_enough && not_contained) uf.merge(i,j);
  }
  
  cout << (uf.same(0, N+1) ? "Yes" : "No") << endl;
  return 0;
}