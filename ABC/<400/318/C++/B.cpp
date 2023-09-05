#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[110][110];
int N, answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    int A, B, C, D; cin >> A >> B >> C >> D;
    rep(x, A, B)rep(y, C, D) F[x][y] = true;
  }
  
  rep(x, 0, 101)rep(y, 0, 101) answer += F[x][y];
  cout << answer << endl;
  return 0;
}