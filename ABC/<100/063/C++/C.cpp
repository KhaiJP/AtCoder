#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer, m = 1e9;

int main(){
  cin >> N;
  rep(i, 0, N){
    int s; cin >> s;
    answer += s;
    if(s%10 != 0) m = min(m, s);
  }

  if(answer%10 != 0) cout << answer << endl;
  else cout << max(answer-m, 0) << endl;
  return 0;
}