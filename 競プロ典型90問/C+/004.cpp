#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[2023][2023], H, W, sumR[2023], sumC[2023];

int main(){
  cin >> H >> W;
  rep(row, 1, H+1)rep(col, 1, W+1) cin >> A[row][col];

  rep(row, 1, H+1){
    int tot = 0;
    rep(col, 1, W+1) tot += A[row][col];
    sumR[row] = tot;
  }
  rep(col, 1, W+1){
    int tot = 0;
    rep(row, 1, H+1) tot += A[row][col];
    sumC[col] = tot;
  }

  rep(row, 1, H+1){
    rep(col, 1, W+1) cout << sumR[row] + sumC[col] - A[row][col] << ' ';
    cout << '\n';
  }

  cout << endl;
  return 0;
}