#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int a[100010];

int main(){
  int N; cin >> N;
  
  rep(i, 0, N) cin >> a[i];

  int count = 0;
  rep(i, 0, N) count += a[i] % 2 == 0;

  cout << (count == N ? "second" : "first") << endl;
  return 0;
}