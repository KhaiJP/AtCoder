#include<iostream>
#include<set>
#include<atcoder/all>
using namespace std;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s) ; i < (t); ++i)

int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};
int H, W;
set<int> s;
bool F[1010][1010];

int main(){
  cin >> H >> W;
  rep(r, 1, H+1)rep(c, 1, W+1){
    char s; cin >> s;
    F[r][c] = s == '#';
  }

  UF uf(H*W);
  rep(r, 1, H+1)rep(c, 1, W+1)if(F[r][c]){
    rep(k, 0, 8)if(F[r+DR[k]][c+DC[k]]){
      uf.merge(W*(r-1) + c-1, W*(r+DR[k]-1) + c+DC[k]-1);
    }
  }
  rep(r, 1, H+1)rep(c, 1, W+1)if(F[r][c]){
    s.insert(uf.leader(W*(r-1) + c-1));
  }
  cout << s.size() << endl;
  return 0;
}