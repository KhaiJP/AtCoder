#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, A, B; cin >> N >> A >> B;

  rep(i, 1, N+1){
    int C; cin >> C;
    if(A+B == C){
      cout << i << endl;
      return 0;
    }
  }
}