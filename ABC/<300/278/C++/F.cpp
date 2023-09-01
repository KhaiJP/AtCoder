#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S[20];
map<char, set<int>> E;
// win_lose[u][0b11001] = 1 <==> choosing S[u], with S[1] and S[2], hemce u = 1 or 2,
// are already used, leads to victory. if 0 lose, and not revealed yet if -1  
int N, mask, win_lose[20][1 << 16];

bool dfs(int u){
  if(win_lose[u][mask] != -1) return win_lose[u][mask];
  
  char &c = S[u].back();
  bool opp_wins = false;
  for(auto v : E[c])if( mask & (1 << v) ){
    mask -= 1 << v;
    opp_wins = dfs(v);
    mask += 1 << v;

    // if there is one or more episode that the opponent wins then one cannot win
    if(opp_wins) break;
  }
  
  // opponent wins, then one loses
  win_lose[u][mask] = !opp_wins;
  return win_lose[u][mask];
}

int main(){
  cin >> N;
  rep(i, 0, N){
    string s; cin >> s;
    S[i] = s;
    E[s[0]].insert(i);
  }

  rep(u, 0, 20)rep(m, 0, 1 << 16) win_lose[u][m] = -1;
  rep(u, 0, N) mask += ( 1 << u );

  rep(u, 0, N){
    mask -= ( 1 << u );
    bool haswon = dfs(u);
    mask += ( 1 << u );
    if(haswon){
      cout << "First"<< endl;
      return 0;
    }
  }

  cout << "Second" << endl;
  return 0;
}