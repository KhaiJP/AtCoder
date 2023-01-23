#include<iostream>
#include<utility>
#include<string>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
const ll MOD = 998244353;

int main(){
  ll N; cin >> N;
  string A, B; cin >> A >> B;
  rep(i,0,N){
    if((int)(A[i]-'0') > (int)(B[i]-'0')) swap(A[i],B[i]);
  }
  ll a = 0, b = 0;
  ll ten = 1;
  rep(i,0,N){
    a += ( (ll)( A[N-1-i] - '0' )*ten ) % MOD;
    b += ( (ll)( B[N-1-i] - '0' )*ten ) % MOD;
    ten = (ten*(ll)10)%MOD;
  }
  cout << ( (a%MOD) * (b%MOD) ) % MOD << endl;
  return 0;
}