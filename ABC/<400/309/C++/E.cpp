#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool insured[300010];
int  Y[300010];
vector<int> children[300010];

void dfs(int me = 1, int y=0){
  y = max(y, Y[me]);
  if(y) insured[me] = true;
  for(auto child : children[me]) dfs(child, y-1);
}

int main(){
  int N, M; cin >> N >> M;

  rep(i, 2, N+1){
    int p; cin >> p;
    children[p].push_back(i);
  }
  rep(i, 0, M){
    int x, y; cin >> x >> y; ++y;
    insured[x] = true;
    Y[x] = max(Y[x], y);
  }

  dfs();

  int answer = 0;
  rep(i, 1, N+1) answer += insured[i];
  cout << answer << endl;
  return 0;
}