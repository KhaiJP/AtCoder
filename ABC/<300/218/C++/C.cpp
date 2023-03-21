#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define yes "Yes"
#define noo "No"

vector tmp(205, vector<char>(205));

void rotate(vector<vector<char>> &M, vector<vector<char>> &A, int H, int W){
  vector tmp(W, vector<char>(H));
  rep(i, 0, H)rep(j, 0, W) tmp[(W-1 - j)][i] = M[i][j];
  rep(i, 0, W)rep(j, 0, H) A[i][j] = tmp[i][j];
}

int main(){
  int N; cin >> N;
  vector S(N, vector<char>(N)), T(N, vector<char>(N));
  rep(i, 0, N)rep(j, 0, N) cin >> S[i][j];
  rep(i, 0, N)rep(j, 0, N) cin >> T[i][j];

  // let the upper/right/down/light bound of figure S is u/r/d/l, 
  // then urdlS = {u, N-1 - r, N-1 - d, l}
  int urdlS[4], urdlT[4];
  rep(k, 0, 4){
    rep(i, 0, N*N)if(S[i/N][i%N] == '#'){urdlS[k] = i/N; break;}
    rotate(S, S, N, N);
    rep(i, 0, N*N)if(T[i/N][i%N] == '#'){urdlT[k] = i/N; break;}
    rotate(T, T, N, N);
  }

  // Hs/Ws is the hight/width of figure S
  int Hs = (N-1 -urdlS[2]) - urdlS[0] + 1, Ws = (N-1 -urdlS[1]) - urdlS[3] + 1;
  int Ht = (N-1 -urdlT[2]) - urdlT[0] + 1, Wt = (N-1 -urdlT[1]) - urdlT[3] + 1;
  
  vector s1(Hs, vector<char>(Ws)), s2(Ws, vector<char>(Hs));
  rep(i, 0, Hs)rep(j, 0, Ws) s1[i][j] = S[i+urdlS[0]][j+urdlS[3]];
  vector t(Ht, vector<char>(Wt));
  rep(i, 0, Ht)rep(j, 0, Wt) t[i][j] = T[i+urdlT[0]][j+urdlT[3]];

  bool flag = false;
  flag = flag || s1 == t; rotate(s1, s2, Hs, Ws);
  flag = flag || s2 == t; rotate(s2, s1, Ws, Hs);
  flag = flag || s1 == t; rotate(s1, s2, Hs, Ws);
  flag = flag || s2 == t;

  cout << (flag ? yes : noo) << endl;
  return 0;
}