#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  
  cout << (1900 * M + 100 * (N - M)) * (1 << M) << endl;
  return 0;
}