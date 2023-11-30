#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, answer, R[2010], C[2010];
bool F[2010][2010];

int main(){
  cin >> N;
  
  rep(i, 1, N+1)rep(j, 1, N+1){
    char c; cin >> c;
    F[i][j] = c == 'o';
    R[i] += F[i][j];
    C[j] += F[i][j];
  }

  rep(i, 1, N+1)rep(j, 1, N+1)if(F[i][j]){
    answer += (R[i] - 1) * (C[j] - 1);
  }

  cout << answer << endl;
  return 0;
}