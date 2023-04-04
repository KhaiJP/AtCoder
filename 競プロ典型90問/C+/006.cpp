#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

int next_c[26][100010];

int main(){
  int N, K; cin >> N >> K;
  string S; cin >> S;
  rep(c, 0, 26) next_c[c][N] = N;
  rrep(i, N-1, 0)rep(c, 0, 26){
    if( (int)(S[i] - 'a') == c ) next_c[c][i] = i;
    else next_c[c][i] = next_c[c][i+1];
  }

  string answer = "";
  int idx = 0;
  rep(i, 1, K+1)rep(c, 0, 26){
    int next_idx = next_c[c][idx];
    int feasible_length = N - next_idx - 1 + i;
    if( feasible_length >= K ){
      answer += (char)('a' + c);
      idx = next_idx + 1;
      break;
    }
  }

  cout << answer << endl;
  return 0;
}