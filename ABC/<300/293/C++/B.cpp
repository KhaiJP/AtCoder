#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool b[200010];

int main(){
  int n; cin >> n;

  set<int> s; rep(i, 1, n+1) s.insert(i);
  rep(i, 1, n+1){
    int a; cin >> a;
    if(!b[i]){
      s.erase(a);
      b[a] = true;
    }
  }

  cout << s.size() << '\n';
  for(auto a : s) cout << a << ' ';
  cout << endl;
  return 0;
}