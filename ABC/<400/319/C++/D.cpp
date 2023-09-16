#include<iostream>
#include<iomanip>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, L[200010], total, maximum;

bool can_show_with_width_of(ll w){
  ll num_lines = 1, width = 0;
  rep(i, 0, N){
    width += L[i];
    if(width > w){
      ++num_lines;
      width = L[i];
    }
  }
  return num_lines <= M;
}

int main(){
  cin >> N >> M;
  rep(i, 0, N){
    cin >> L[i]; ++L[i];
    total += L[i];
    maximum = max(maximum, L[i]);
  }

  ll l = maximum-1, r = total;
  while(l+1 < r){
    ll mid = (l + r) / 2;
    if(can_show_with_width_of(mid)){
      r = mid;
    }else{
      l = mid;
    }
  }

  cout << r - 1 << endl;
  return 0;
}