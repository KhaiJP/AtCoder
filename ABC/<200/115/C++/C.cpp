#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int answer, N, K, h[100010];

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> h[i];
  sort(h, h+N);

  answer = 1e9;
  rep(i, 0, N-K+1) answer = min(answer, h[i+K-1] - h[i]);
  cout << answer << endl;
  return 0;
}