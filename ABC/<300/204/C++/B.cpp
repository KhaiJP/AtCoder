#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  int answer = 0;
  rep(i, 0, N){
    int A; cin >> A;
    answer += max(A-10, 0);
  }

  cout << answer << endl;
  return 0;
}