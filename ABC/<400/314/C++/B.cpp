#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmin(a, b) a = min((a), (b))

int F[110][40], C[110];
set<int> S;

int main(){
  int N; cin >> N;
  rep(i, 1, N+1){
    cin >> C[i];
    rep(j, 0, C[i]){
      int a; cin >> a;
      F[i][a] = 1;
    }
  }

  int X; cin >> X;
  int m = 1e9;
  rep(i, 1, N+1)if(F[i][X] == 1) chmin(m, C[i]);
  rep(i, 1, N+1)if(C[i] == m && F[i][X] == 1) S.insert(i);
  
  cout << S.size() << endl;
  for(auto p : S) cout << p << ' ';
  cout << endl;
  return 0;
}