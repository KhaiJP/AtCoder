#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  int answer = 0, x = 0;
  rep(i, 0, N){
    char c; cin >> c;
    if(c == 'I') ++x;
    if(c == 'D') --x;
    answer = max(answer, x);
  }
  
  cout << answer << endl;
  return 0;
}