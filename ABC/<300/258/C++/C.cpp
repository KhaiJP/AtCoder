#include<iostream>
#include<string>
using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  int num_rots = 0;
  for(int i=0; i<Q; i++){
    int n, x; cin >> n >> x;
    if(n == 1) num_rots = (num_rots + x)%N;
    if(n == 2) cout << S.at((N-num_rots+x-1)%N) << '\n';
  }
  cout << endl;
  return 0;
}