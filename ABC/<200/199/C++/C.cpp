#include<iostream>
#include<utility>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char S[2][200010];

int main(){
  int N; cin >> N;
  rep(i, 0, 2*N) cin >> S[i/N][i%N];

  bool switched = false;
  int Q; cin >> Q;
  rep(i, 0, Q){
    int T, A, B; cin >> T >> A >> B; --A, --B;
    if(T == 1) swap(S[switched ^ (A/N)][A%N], S[switched ^ (B/N)][B%N]);
    if(T == 2) switched = !switched;
  }

  rep(i, 0, 2*N) cout << S[switched ^ (i/N)][i%N];
  cout << endl;
  return 0;
}