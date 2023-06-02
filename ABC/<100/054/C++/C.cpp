#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[10];

int main(){
  int N, M; cin >> N >> M;
  
  rep(i, 0, M){
    int a, b; cin >> a>> b; --a, --b;
    E[a].insert(b), E[b].insert(a);
  }

  vector<int> v(N-1); rep(i, 0, N-1) v[i] = i+1;

  int answer = 0;
  do{
    if(E[0].count(v[0]) != 1) continue;
    
    bool flag = true;
    rep(i, 0, N-2)if(E[v[i]].count(v[i+1]) != 1){
      flag = false;
      break;
    }
    
    answer += flag;
  }while(next_permutation(v.begin(), v.end()));

  cout << answer << endl;
  return 0;
}