#include<iostream>
#include<set>
#include<vector>
#include<numeric>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

using namespace std;

int main(){
  int N; cin >> N;
  vector r(N, vector<int>(2,0)); rep(i,0,N) cin >> r[i][0] >> r[i][1];
  set<vector<int>> S;
  rep(i,0,N-1) rep(j,i+1, N){
    int x = r[i][0]-r[j][0], y = r[i][1]-r[j][1];
    int g = gcd(x, y);
    x /= g, y /= g;
    if(x!=0 || y!=0){
      S.insert({x,y});
      S.insert({-x,-y});
    }
  }
  cout << S.size()<< endl;
  return 0;
}