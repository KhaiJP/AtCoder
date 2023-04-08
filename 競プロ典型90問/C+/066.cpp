#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int L[110], R[110];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> L[i] >> R[i];

  // brute-force
  double answer = 0.;
  rep(i, 0, N-1)rep(j, i+1, N){
    int n_inversion = 0, total = 0;
    rep(l, L[i], R[i]+1)rep(r, L[j], R[j]+1){
      if(l > r) ++n_inversion;
      ++total;
    }

    answer += double(n_inversion) / total;
  }

  cout.precision(10);
  cout << fixed << answer << endl;
  return 0;
}