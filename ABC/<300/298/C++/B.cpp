#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[110][110], B[110][110], tmp[110][110];

int main(){
  int N; cin >> N;
  rep(i, 0, N)rep(j, 0, N) cin >> A[i][j];
  rep(i, 0, N)rep(j, 0, N) cin >> B[i][j];

  rep(l, 0, 4){
    bool ok = true;
    rep(i, 0, N)rep(j, 0, N){
      if(A[i][j] == 1) ok = ok & B[i][j] == 1;
    }
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }

    // quarter rotation
    rep(i, 0, N)rep(j, 0, N) tmp[N-j-1][i] = A[i][j];
    rep(i, 0, N)rep(j, 0, N) A[i][j] = tmp[i][j];
  }

  cout << "No" << endl;

  return 0;
}