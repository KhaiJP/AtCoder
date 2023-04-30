#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010];

int main(){
  int N; cin >> N;
  int tot = 0;
  rep(i, 0, N){
    cin >> A[i];
    tot = tot ^ A[i];
  }

  rep(i, 0, N) cout << (tot ^ A[i]) << ' ';
  cout << endl;
  return 0;
}