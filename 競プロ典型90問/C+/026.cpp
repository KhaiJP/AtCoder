#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[100010];
bool colour[100010];
bool visited[100010];

void dfs(int u){
  visited[u] = true;
  for(auto v : E[u])if(!visited[v]){
    colour[v] = !colour[u];
    dfs(v);
  }
}

int main(){
  int N; cin >> N;
  rep(i, 0, N-1){
    int A, B; cin >> A >> B;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  dfs(1);
  
  // find majority colour. if s, the sum, is greater than or equal to N/2, the majority is "true".
  int s = 0;
  rep(u, 1, N+1) s += colour[u];
  bool flag = s >= N/2;

  // n count the number of prints
  int n = 0;
  rep(u, 1, N+1){
    if(colour[u] == flag){
      cout << u << ' ';
      ++n;
    }
    if(n == N/2) break;
  }

  
  cout << endl;
  return 0;
}