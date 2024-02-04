#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, K, H[200010], answer;

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> H[i];
  sort(H, H+N, greater<ll>());
  rep(i, K, N) answer += H[i];
  cout << answer << endl;
  return 0;
}