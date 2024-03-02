#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N;
bool F[110][110];

int main(){
  cin >> N;
  rep(i, 1, N+1)rep(j, 1, N+1){
    int A; cin >> A;
    F[i][j] = A == 1;
  }

  rep(i, 1, N+1){
    rep(j, 1, N+1)if(F[i][j]) cout << j << ' ';
    cout << endl;
  }
  
  return 0;
}