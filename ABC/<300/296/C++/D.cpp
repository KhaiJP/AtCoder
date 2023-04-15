#include<iostream>
using namespace std;
using ll = int64_t;

const ll INF = 100000000000000000;
int main(){
  ll N, M; cin >> N >> M;
  
  ll answer = INF;
  for(ll a = 1; a * a < M + a; ++a){
    ll b = (M + a - 1) / a;
    if(b <= N) answer = min(answer, a * b);
  }

  cout << (answer < INF ? answer : -1) << endl;
  return 0;
}