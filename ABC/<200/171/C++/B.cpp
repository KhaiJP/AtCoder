#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int p[1010], N, K, answer;

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> p[i];
  sort(p, p+N);
  rep(i, 0, K) answer += p[i];
  cout << answer << endl;
  return 0;
}