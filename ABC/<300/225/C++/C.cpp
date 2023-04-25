#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll B[100010][10];

int main(){
  ll N, M; cin >> N >> M;
  rep(i, 0, N)rep(j, 0, M) cin >> B[i][j];
  
  rep(i, 0, N)rep(j, 0, M){
    if(i > 0 && B[i][j] != B[i-1][j] + 7){
      cout << "No" << endl;
      return 0;
    }
    if(j > 0 && B[i][j] != B[i][j-1] + 1){
      cout << "No" << endl;
      return 0;
    }
    if(j < M - 1 && B[i][j] % 7 == 0){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}