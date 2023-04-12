#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[60][60];

int main(){
  int H, W; cin >> H >> W;
  rep(i, 0, H)rep(j, 0, W) cin >> A[i][j];

  rep(i1, 0, H-1)rep(i2, i1+1, H)rep(j1, 0, W-1)rep(j2, j1+1, W){
    if(A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}

// reference   ->   https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958
// a matrix that enjoys the condition shown in the problem is called Monge
// -> for a matrix A, choose two rows and columns, and we have 4 intersections;
//             -  -  -  -  -  -  - 
//             -  ul -  -  -  ur -
//             -  -  -  -  -  -  -    ->   ul + lr  <=  ll + ur
//             -  ll -  -  -  lr -
//             -  -  -  -  -  -  -
// This property can naively checked as shown above in O(H^2 W^2) time.
// However there is a O(HW) algorithm since it can be said that
// A[i][j] + A[i+1][j+1]  <=  A[i][j+1] + A[i+1][j]  <-->  A is Monge.
// Statement <- is evident. Statement -> can be confirmed as following;
// Given A[i][j]   + A[i+1][j+1]  <=  A[i][j+1] + A[i+1][j]
// and   A[i][j+1] + A[i+1][j+2]  <=  A[i][j+2] + A[i+1][j+1],
// A[i][j+2] + A[i+1][j] - ( A[j+1][j+2] + A[i][j] )
// = ( A[i][j+2] - A[i+1][j+2] )  +  ( A[i+1][j] - A[i][j] )
// >= ( A[i][j+1] - A[i+1][j+1] )  +  ( A[i+1][j+1] - A[i][j+1])   =   0
// and repeating this calculation.