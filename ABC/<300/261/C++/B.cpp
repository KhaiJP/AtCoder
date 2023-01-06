#include <iostream>
#include <vector>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector tourRes(N, vector<char>(N, ' '));
  rep(i,0,N)rep(j,0,N) cin >> tourRes[i][j];
  bool flag = true;
  rep(i,0,N)rep(j,i, N){
    if( i == j ) flag = flag && tourRes[i][j] == '-';
    else{
      bool tmpflag1 = tourRes[i][j] == 'W' && tourRes[j][i] == 'L';
      bool tmpflag2 = tourRes[i][j] == 'L' && tourRes[j][i] == 'W';
      bool tmpflag3 = tourRes[i][j] == 'D' && tourRes[j][i] == 'D';
      flag = flag && (tmpflag1 || tmpflag2 || tmpflag3);
    }
  }
  cout << (flag ? "correct" : "incorrect") << endl;
  return 0;
}