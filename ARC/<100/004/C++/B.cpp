#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int d[510];

int main(){
  int N; cin >> N;

  rep(i, 0, N) cin >> d[i];
  
  int total = 0, longest = 0;
  rep(i, 0, N){
    total += d[i];
    longest = max(longest, d[i]);
  }

  cout << total << '\n' << max(2*longest - total, 0) << '\n';
  return 0;
}