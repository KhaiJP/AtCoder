#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// 0 times telepotation is considered to stay at town 1.
// this town transitions apparently have a period which is smaller than or equal to N -> O(N)
// let us consider the transition pattern of the example 2;
// 1(0) -> 6(1) -> 2(2) -> 5(3) -> 3(4) -> 2(5) -> ...  / here (k) represents # of teleportations
// in this example, the period is 3. let the fist # of teleportations be called break_point, 2

// place[k] : where you are after k teleportations
// order[j] : how many teleportations bring you to town j
ll A[200010], place[200010], order[200010];

int main(){
  ll N, K; cin >> N >> K;
  // initialize order[j] by -1
  rep(j, 0, N+1) order[j] = -1;
  rep(i, 1, N+1) cin >> A[i];

  // k : # of teleportations
  ll k = 0, town = 1, period, break_point;
  while(true){
    if(order[town] == -1){
      order[town] = k;
      // 
      place[k] = town;
      ++k;
      town = A[town];
    }else{
      period = k - order[town];
      break_point = order[town];
      break;
    }
  }
  
  if(K < break_point) cout << place[K] << endl;
  else cout << place[(K - break_point)%period + break_point] << endl;

  return 0;
}