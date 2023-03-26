#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];

void dfs(int current, int pre){
  cout << current << ' ';
  
  for(auto next : E[current])if(next != pre){
    dfs(next, current);
    cout << current << ' ';
  }
}

int main(){
  int N; cin >> N;
  
  rep(i, 1, N){
    int A, B; cin >> A >> B;
    E[A].push_back(B);
    E[B].push_back(A);
  }rep(i, 1, N+1) sort(E[i].begin(), E[i].end());

  dfs(1, 0);
  cout << endl;
  return 0;
}