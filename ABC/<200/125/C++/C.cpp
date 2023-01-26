#include<iostream>
#include<numeric>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

//  lgcd[i] = gcd(A_1:(i-1)), rgcd[i] = gcd(A_(P+1):N))
int lgcd[112345], rgcd[112345], A[112345];

int main(){
  int N; cin >> N;
  rep(i,1,N+1)  cin >> A[i];
  rep(i,1,N+1)  lgcd[i] = gcd(lgcd[i-1], A[i-1]);
  rrep(i,N-1,0) rgcd[i] = gcd(rgcd[i+1], A[i+1]);

  int answer = 0;
  rep(i,1,N+1) answer = max(answer, gcd(lgcd[i], rgcd[i]));
  
  cout << answer << endl;
  return 0;
}
