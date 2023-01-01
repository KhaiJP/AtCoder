#include<iostream>
#include<atcoder/all>
#include<unordered_set>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
using namespace atcoder;
typedef pair<int, int> P;

int main(){
  int N; cin >> N;
  vector<P> XY(N);
  rep(i,0,N){
    int X, Y; cin >> X >> Y;
    XY[i] = P(X, Y);
  }
  dsu uf(N);
  rep(i,0,N)rep(j,i+1,N){
    bool flag1 = XY[i].second == XY[j].second && (XY[i].first-XY[j].first)*(XY[i].first-XY[j].first) == 1;
    bool flag2 = XY[i].second + 1 == XY[j].second && (XY[i].first == XY[j].first || XY[i].first + 1 == XY[j].first);
    bool flag3 = XY[i].second - 1 == XY[j].second && (XY[i].first == XY[j].first || XY[i].first - 1 == XY[j].first);
    if(flag1 || flag2 || flag3) uf.merge(i,j);
  }
  unordered_set<int> S;
  rep(i,0,N) S.insert(uf.leader(i));
  cout << S.size() << endl;
  return 0;
}
