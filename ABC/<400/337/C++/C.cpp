#include<iostream>
using namespace std;

int N, nxt[300010], idx;

int main(){
  cin >> N;
  for(int i = 1; i <= N; ++i){
    int A; cin >> A;
    A = max(A, 0);
    nxt[A] = i;
  }

  while(nxt[idx] != 0){
    idx = nxt[idx];
    cout << idx << ' ';
  }cout << endl;

  return 0;
}