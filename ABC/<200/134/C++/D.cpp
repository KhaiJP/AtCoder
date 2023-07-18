#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

int a[200010], b[200010];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1) cin >> a[i];
  
  int M = 0;
  rrep(i, N, 1){
    int r = 0;
    for(int j = 2*i; j <= N; j += i) r += b[j];
    b[i] = a[i] ^ (r & 1);
    M += b[i];
  }

  cout << M << endl;
  rep(i, 1, N+1)if(b[i]) cout << i << ' ';
  cout << endl;
  return 0;
}