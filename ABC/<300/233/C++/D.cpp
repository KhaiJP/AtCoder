#include<iostream>
#include<unordered_map>
#define rep(i,t) for(int i=0;i<(t);++i)
using namespace std;

int main(){
  int64_t n, k; cin >> n >> k;
  unordered_map<int64_t, int64_t> p;
  int64_t pfx = 0;
  int64_t ans = 0;
  rep(i,n){
    p[pfx] += 1;
    int64_t a; cin >> a;
    pfx += a;
    ans += p[pfx-k];
  }
  cout << ans << endl;
  return 0;
}
