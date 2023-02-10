#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int A, B; cin >> A >> B;
  int answer = 1;
  rep(i,0,A-B) answer *= 32;
  
  cout << answer << endl;
  return 0;
}