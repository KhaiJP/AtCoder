#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, P, Q; cin >> N >> P >> Q;
  int minD = 1e9;
  rep(i, 0, N){
    int D; cin >> D;
    minD = min(minD, D);
  }

  cout << min(P, Q+minD) << endl;
  return 0;
}