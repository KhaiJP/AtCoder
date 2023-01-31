#include<iostream>
#include<deque>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int Q; cin >> Q;

  deque<pair<ll,ll>> dq;
  rep(i,0,Q){
    int l; cin >> l;
    if(l == 1){
      ll x, c; cin >> x >> c;
      dq.push_back({c,  x});
    }
    else {
      ll c; cin >> c;
      ll output = 0;
      while(c){
        ll &d = dq.front().first;
        ll &y = dq.front().secomd;

        if(d > c){
          output += c * y;
          d -= c;
          c = 0;
        }
        else {
          output += d * y;
          c -= d;
          dq.pop_front();
        }
        
      }
      cout << output << endl;
    }
  }
  return 0;
}