#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<ll, ll> P[330];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> P[i].first >> P[i].second;
  
  int answer = 0;
  rep(i, 0, N-2)rep(j, i+1, N-1)rep(k, j+1, N){
    int ax = P[i].first, ay = P[i].second;
    int bx = P[j].first, by = P[j].second;
    int cx = P[k].first, cy = P[k].second;
    
    answer += (ax - bx)*(ay - cy) != (ax - cx)*(ay - by);
  }
  
  cout << answer << endl;
  return 0;
}