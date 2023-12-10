#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W, AB[2][10][10], inf = 1e9, answer = inf;
int sigma_h[] = {0, 1, 2, 3, 4};
int sigma_w[] = {0, 1, 2, 3, 4};

int main(){
  cin >> H >> W;
  rep(t, 0, 2)rep(r, 0, H)rep(c, 0, W) cin >> AB[t][r][c];
  
  do{
    do{
      bool f = true;
      rep(r, 0, H)rep(c, 0, W){
        int i = sigma_h[r], j = sigma_w[c];
        f = f && AB[0][i][j] == AB[1][r][c];
      }
      if(!f) continue;
      
      int n_inversion = 0;
      rep(r, 1, H)rep(i, 0, r){
        n_inversion += sigma_h[r] < sigma_h[i];
      }
      rep(c, 1, W)rep(j, 0, c){
        n_inversion += sigma_w[c] < sigma_w[j];
      }
      answer = min(answer, n_inversion);

    }while(next_permutation(sigma_w, sigma_w+W));
  }while(next_permutation(sigma_h, sigma_h+H));

  cout << (answer < inf ? answer : -1) << endl;
  return 0;
}