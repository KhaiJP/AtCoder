#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int L, Q; cin >> L >> Q;
  set<int> S;
  S.insert(0), S.insert(L);

  while(Q){
    int c, x; cin >> c >> x;
    if(c == 1) S.insert(x);
    if(c == 2){
      auto itr = S.lower_bound(x);
      cout << ( *itr - *(--itr) ) << '\n';
    }
    --Q;
  }

  cout << endl;
  return 0;
}