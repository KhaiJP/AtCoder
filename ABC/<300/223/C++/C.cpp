#include<iostream>
#include<iomanip>
#include<deque>
using namespace std;
using P = pair<double, double>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Length[100010], Velocity[100010];
deque<P> q;
double eps = 1e-18;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> Length[i] >> Velocity[i];

  rep(i, 0, N) q.push_back({Length[i], Velocity[i]});
  double d = 0;
  while(q.size() > 1){
    double l_len = q.front().first,  r_len = q.back().first;
    double l_vel = q.front().second, r_vel = q.back().second;
    double t = min(l_len/l_vel, r_len/r_vel);
    
    d += l_vel * t;
    q.front().first -= l_vel * t;
    q.back().first  -= r_vel * t;
    if(q.front().first <= eps) q.pop_front();
    if(q.back().first  <= eps) q.pop_back();
  }
  
  if(q.size()) d += q.front().first / 2;
  cout << fixed << setprecision(9) << d << endl;
  return 0;
}