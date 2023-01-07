#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int find_pq(ll N);

int main(){
  int T; cin >> T;
  rep(t,0,T){
    ll N; cin >> N;
    find_pq(N);
  }
  cout << endl;
  return 0;
}

int find_pq(ll N){
  ll two = 2;
  if(N%two == 0){
    N /= two;
    if(N%two == 0){
      cout << two << ' ' << N/two << '\n';
      return 0;
    }else{
      cout << (ll)sqrt(N) << ' ' << two << '\n';
      return 0;
    }
  }
  for(ll i = 3; i*i*i <= N; i += 2){
    if(N%i == 0){
      N /= i;
      if(N%i == 0){
        cout << i << ' ' << N/i << '\n';
        return 0;
      }else{
        cout << (ll)sqrt(N) << ' ' << i << '\n';
        return 0;
      }
    }
  }
}