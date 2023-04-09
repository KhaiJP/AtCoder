#include<iostream>
#include<utility>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll answer;

void gcd_ish(ll a, ll b){
  if(a != b){
    answer += a / b;
    if(a % b) gcd_ish(b, a % b);
    else answer -= 1;
  }else if(b == 1) answer += a - 1;
}

int main(){
  ll A, B; cin >> A >> B;
  if(B > A) swap(A, B);

  gcd_ish(A, B);
  cout << answer << endl;
  return 0;
}