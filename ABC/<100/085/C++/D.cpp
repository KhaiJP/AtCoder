#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef int64_t ll;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)

int main(){
  ll N, H; cin >> N >> H;
  vector<ll> A(N), B(N); rep(i,0,N) cin >> A[i] >> B[i];
  ll maxA = 0;
  rep(i,0,N) maxA = max(maxA, A[i]);
  priority_queue<ll> actions;
  actions.push(maxA);
  rep(i,0,N)if(B[i] > maxA) actions.push(B[i]);
  ll num_throws = 0;
  while(!actions.empty()){
    ll b = actions.top(); actions.pop();
    H -= b;
    ++num_throws;
    if(H <= 0) { cout << num_throws << endl; return 0;}
  }
  cout << (H + maxA -1)/maxA + num_throws << endl;
  return 0;
}