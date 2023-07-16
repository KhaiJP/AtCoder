#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  int answer = 0;
  rep(i, 1, N+1) answer += to_string(i).size() & 1;
  cout << answer << endl;
  return 0;
}