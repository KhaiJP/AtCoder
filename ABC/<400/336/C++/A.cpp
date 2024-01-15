#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string answer = "L";
  int N; cin >> N;
  rep(i, 0, N) answer += 'o';
  answer += "ng";
  cout << answer << endl;
  return 0;
}