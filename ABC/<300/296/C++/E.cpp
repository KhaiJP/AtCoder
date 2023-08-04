#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool visited[200010], win[200010];
int A[200010];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1) cin >> A[i];
  
  rep(i, 1, N+1)if(!visited[i]){
    set<int> log;
    vector<int> v;
    int u = i;
    while(!visited[u]){
      visited[u] = true;
      v.push_back(u);
      log.insert(u);
      u = A[u];
    }
    if(log.count(u) == 0) continue;
    bool flag = false;
    for(auto a : v){
      if(a == u) flag = true;
      win[a] = flag;
    }
  }
  
  int answer = 0;
  rep(i, 1, N+1) answer += win[i];
  cout << answer << endl;
  return 0;
}
