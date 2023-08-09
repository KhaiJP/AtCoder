#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, answer, a = 1, b = 10;

int main(){
  cin >> N;
  rep(i, 0, 9){
    answer += a * (N / b);
    ll r = N % b;
    if(r >= 2 * a - 1)  answer += a;
    else if(r >= a) answer += r - a + 1;
    a *= 10;
    b *= 10;
  }

  cout << answer << endl;
  return 0;
}
