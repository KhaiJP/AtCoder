#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W, K, inf = 1e9;
int answer = inf;

void sub_solve(string &s, int w){
  s += 'x';
  int idx = -1;
  rep(i, 0, w+1)if(s[i] == 'x'){
    if(i - idx - 1 >= K){
      vector<int> pfx(i-idx, 0);
      rep(k, idx+1, i) pfx[k-idx] = pfx[k-idx-1] + (s[k] == '.');
      rep(k, K, i-idx) answer = min(answer, pfx[k]-pfx[k-K]);
    }
    idx = i;
  }
}

void solve(vector<string> &F, int h, int w){
  rep(i, 0, h) sub_solve(F[i], w);
}

int main(){
  cin >> H >> W >> K;
  vector<string> S(H), T(W, "");

  rep(i, 0, H) cin >> S[i];
  rep(j, 0, W)rep(i, 0, H) T[j] += S[i][j];

  solve(S, H, W);
  solve(T, W, H);

  cout << (answer < inf ? answer : -1) << endl;
}