#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[100010];
int pre[100010];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int A, B; cin >> A >> B;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  E[0].push_back(1);
  rep(u, 0, N+1) pre[u] = -1;

  deque<int> q; q.push_back(0);
  while(!q.empty()){
    int u = q.front(); q.pop_front();

    for(auto v : E[u])if(pre[v] == -1){
      pre[v] = u;
      q.push_back(v);
    }
  }

  cout << "Yes" << '\n';
  rep(u, 2, N) cout << pre[u] << '\n';
  cout << endl;
  return 0;
}