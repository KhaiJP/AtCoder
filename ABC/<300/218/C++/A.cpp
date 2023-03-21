#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N; --N;
  rep(i, 0, N){char c; cin >> c;};
  char c; cin >> c;
  cout << ( c == 'o' ? "Yes" : "No") << endl;
  return 0;
}