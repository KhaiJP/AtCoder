#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
  int N, Q; cin >> N >> Q;
  set<int> unvisited;
  int k = 1;

  rep(i, 0, Q){
    int e; cin >> e;
    if(e == 1){
      unvisited.insert(k);
      ++k;
    }
    if(e == 2){
      int x; cin >> x;
      unvisited.erase(x);
    }
    if(e == 3){
      cout << *unvisited.begin() << '\n';
    }
  }

  cout << endl;
  return 0;
}