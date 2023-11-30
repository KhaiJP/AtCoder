#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, L, answer;

int main(){
  cin >> N >> L;
  rep(i, 0, N){
    int a; cin >> a;
    answer += a >= L;
  }

  cout << answer << endl;
  return 0;
}