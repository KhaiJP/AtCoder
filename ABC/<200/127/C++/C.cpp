#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// n_gate_open[i] = m : ID card i opens m gates
int n_gate_open[100010];

int main(){
  int N, M; cin >> N >> M;

  // solved by imos-method
  rep(i, 0, M){
    int L, R; cin >> L >> R;
    n_gate_open[L] += 1, n_gate_open[R+1] -= 1;
  }
  rep(i, 1, N+1) n_gate_open[i] += n_gate_open[i-1];

  int answer = 0;
  rep(i, 0, N+1) answer += n_gate_open[i] == M;

  cout << answer << endl;
  return 0;
}