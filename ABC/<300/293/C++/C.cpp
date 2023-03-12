#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[11][11];
char C[22];

int main(){
  int H, W; cin >> H >> W;
  rep(i, 1, H+1)rep(j, 1, W+1) cin >> A[i][j];
  

  rep(i,0,H-1) C[i] = 'd';  
  rep(i,H-1,H+W-2) C[i] = 'r';
  ll answer = 0;

  do{
    int h = 1, w = 1;
    set<ll> buff;
    buff.insert(A[h][w]);
    bool flag = true;

    rep(i, 0, H+W-2){
      if(C[i] == 'd') ++h;
      if(C[i] == 'r') ++w;
      if(buff.count(A[h][w]) == 1){
        flag = false;
        break;
      }
      buff.insert(A[h][w]);
    }

    if(flag) ++answer;

  }while( next_permutation(C, C+H+W-2) );
  
  cout << answer << endl;
  return 0;
}