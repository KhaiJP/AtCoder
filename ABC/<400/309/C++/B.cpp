#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char original[110][110], rotated[110][110];

int main(){
  int N; cin >> N;
  rep(i, 0, N)rep(j, 0, N) cin >> original[i][j];

  rep(j, 1, N) rotated[0][j] = original[0][j-1];
  rep(i, 1, N) rotated[i][N-1] = original[i-1][N-1];
  rep(j, 0, N-1) rotated[N-1][j] = original[N-1][j+1];
  rep(i, 0, N-1) rotated[i][0] = original[i+1][0];
  rep(i, 1, N-1)rep(j, 1, N-1) rotated[i][j] = original[i][j];

  rep(i, 0, N){
    rep(j, 0, N) cout << rotated[i][j];
    cout << endl;
  }
  
  return 0;
}