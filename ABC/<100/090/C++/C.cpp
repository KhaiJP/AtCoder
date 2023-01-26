#include<iostream>
using namespace std;

int main(){
  int64_t N, M; cin >> N >> M;

  if(N > 1 && M > 1) cout << (N-2)*(M-2) << endl;
  else if(N == 1 && M ==1) cout << 1 << endl;
  else cout << (max(N, M) - 2) << endl;

  return 0;
}