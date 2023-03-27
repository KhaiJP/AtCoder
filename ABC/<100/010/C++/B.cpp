#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int n; cin >> n;
  
  int answer = 0;
  rep(i, 0, n){
    int a; cin >> a;
    answer += a%2 == 0;
    answer += 2 * (a%6 == 5 || a%6 == 0);
  }
  cout << answer << endl;
  return 0;
}