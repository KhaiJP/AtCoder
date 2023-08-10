#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)

int answer, imos[100010][33];

int main(){
  int N, C; cin >> N >> C;
  rep(i, 0, N){
    int a, b, c; cin >> a >> b >> c; --a;
    ++imos[a][c];
    --imos[b][c];
  }

  rep(c, 1, C+1)rep(i, 1, 100010) imos[i][c] += imos[i - 1][c];
  rep(c, 1, C+1)rep(i, 0, 100010)if(imos[i][c]) imos[i][c] = 1;
  
  rep(i, 0, 100010){
    int cnt = 0;
    rep(c, 1, C+1) cnt += imos[i][c];
    chmax(answer, cnt);
  }

  cout << answer << endl;
  return 0;
}
