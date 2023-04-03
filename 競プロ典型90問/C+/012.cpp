#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char Paint[2000*2000+20];

int main(){
  int H, W; cin >> H >> W;
  int Q; cin >> Q;

  dsu uf(H*W+1);

  while(Q){
    int t; cin >> t;
    if(t == 1){
      int r, c; cin >> r >> c; --r, --c;
      Paint[r*W + c] = 'R';
      if(c+1 < W  && Paint[r*W + c + 1] == 'R') uf.merge(r*W + c, r*W + c + 1);
      if(c-1 >= 0 && Paint[r*W + c - 1] == 'R') uf.merge(r*W + c, r*W + c - 1);
      if(r+1 < H  && Paint[r*W + c + W] == 'R') uf.merge(r*W + c, r*W + c + W);
      if(r-1 >= 0 && Paint[r*W + c - W] == 'R') uf.merge(r*W + c, r*W + c - W);
    }
    if(t == 2){
      int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
      --ra, --ca, --rb, --cb;
      bool cond1 = (Paint[ra*W + ca] == 'R' && Paint[rb*W + cb] == 'R');
      bool cond2 = uf.same(ra*W + ca, rb*W + cb);
      cout << ( cond1 && cond2 ? "Yes" : "No" ) << '\n';
    }

    --Q;
  }
  
  cout << endl;
  return 0;
}