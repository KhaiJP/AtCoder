#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int Q; cin >> Q;
  map<int,int> m;
  rep(q,0,Q){
    int cse; cin >> cse;
    if(cse == 1){
      int x; cin >> x;
      ++m[x];
    }
    if(cse == 2){
      int x, c; cin >> x >> c;
      m[x] = max(m[x]-c, 0);
      if(m[x]==0) m.erase(x);
    }
    if(cse == 3){
      cout << (*m.rbegin()).first - (*m.begin()).first << '\n';
    }
  }
  return 0;
}