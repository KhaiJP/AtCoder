#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, K, n, answer;
vector<int> V;
bool dislike[15], done;

void dfs(int k){
  if(k == n){
    if(answer >= N){
      cout << answer << endl;
      done = true;
    }
    return ;
  }
  for(int a : V){
    answer = 10*answer + a;
    dfs(k+1);
    answer /= 10;
    if(done) break;
  }
  return ;
}

int main(){
  cin >> N >> K;
  rep(i, 0, K){
    int d; cin >> d;
    dislike[d] = true;
  }

  rep(i, 0, 10)if(!dislike[i]) V.push_back(i);
  n = to_string(N).size();
  dfs(0);
  if(!done){
    cout << (V[0] == 0 ? V[1] : V[0]);
    rep(i, 0, n) cout << V[0];
  }
  return 0;
}