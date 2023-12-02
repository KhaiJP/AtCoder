#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<string> R;
string S[10];
int N, M, n = 16;
bool found;

void dfs(string t, int k){
  if(k == N){
    if(3 <= (int)t.size() && R.count(t) == 0){
      found = true;
      cout << t << endl;
    }
    return ;
  }
  rep(i, 1, n+1)if(!found){
    string tmp = ""; rep(j, 0, i) tmp += '_';
    n -= i;
    dfs(t + tmp + S[k], k+1);
    n += i;
  }
}

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> S[i];
  rep(i, 0, N) n -= (int)S[i].size();
  sort(S, S+N);

  rep(i, 0, M){
    string T; cin >> T;
    R.insert(T);
  }

  do{
    dfs(S[0], 1);
    if(found) return 0;
  }while(next_permutation(S, S+N));
  
  cout << -1 << endl;
  return 0;
}