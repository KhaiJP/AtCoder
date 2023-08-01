#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define INF 1000000000

int a[60];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> a[i];

  int answer = -INF;
  rep(i, 0, N){
    int max_tk, max_ak = -INF;
    rep(j, 0, N)if(i != j){
      int tk = 0, ak = 0;

      rep(k, min(i, j), max(i, j) + 1){
        if((k - min(i, j)) & 1 ) ak += a[k];
        else tk += a[k];
      }

      if(max_ak < ak){
        max_ak = ak;
        max_tk = tk;
      }
    }

    answer = max(answer, max_tk);
  }

  cout << answer << endl;
  return 0;
}