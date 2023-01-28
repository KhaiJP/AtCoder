#include<iostream>
using namespace std;
typedef uint64_t ull;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define yes "Yes"
#define noo "No"

int main(){
  int T; cin >> T;

  rep(t,0,T){
    ull a, s; cin >> a >> s;
    if(s < 2*a){ cout << noo << '\n'; continue;}
    if((s - 2*a) & a) cout << noo << '\n';
    else cout << yes << '\n';    
  }
  cout << endl;
  return 0;
}