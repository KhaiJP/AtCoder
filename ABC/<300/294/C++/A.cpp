#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    int A; cin >> A;
    if(A%2 == 0) cout << A << ' ';
  }
  cout << endl;
  return 0;
}