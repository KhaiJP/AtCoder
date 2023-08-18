#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// ct -> current time
int N, M, ct, answer;
set<pair<int, int>> BA;

int main(){
  cin >> N >> M;
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    BA.insert({b, a});
  }
  
  // solve by interval scheduling
  for(auto p : BA){
    int a = p.second, b = p.first;
    if(ct <= a){
      ++answer;
      ct = b;
    }
  }

  cout << answer << endl;
  return 0;
}