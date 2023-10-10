#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, x, answer, a[100010];

int main(){
  cin >> N >> x;
  rep(i, 1, N+1) cin >> a[i];

  rep(i, 1, N+1){
    ll gap = max((ll)0, (a[i] + a[i-1]) - x);
    answer += gap;
    a[i]   -= gap;
  }

  cout << answer << endl;
  return 0;
}