#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[5][5], num_disappointed, num_all;

bool check_if_disappointed(vector<pair<int, int>> &v){
  vector<int> R[4], C[4], Diag, AntiDiag;

  for(auto p : v){
    int &r = p.first, &c = p.second;
    int &n = F[r][c];
    R[r].push_back(n), C[c].push_back(n);
    if(r == c) Diag.push_back(n);
    if(r + c == 4) AntiDiag.push_back(n);
  }

  bool is_disappointed = false;
  // check if Takahashi is disappointed w.r.t. rows 
  rep(r, 1, 4) is_disappointed = is_disappointed || R[r][0] == R[r][1];
  // w.r.t. columns
  rep(c, 1, 4) is_disappointed = is_disappointed || C[c][0] == C[c][1];
  // w.r.t. diagonal componets
  is_disappointed = is_disappointed || Diag[0] == Diag[1];
  // w.r.t. anti_diagonal components
  is_disappointed = is_disappointed || AntiDiag[0] == AntiDiag[1];

  return is_disappointed;
}

int main(){
  rep(r, 1, 4)rep(c, 1, 4) cin >> F[r][c];
  vector<pair<int, int>> V; rep(r, 1, 4)rep(c, 1, 4) V.push_back({r, c});

  do{
    ++num_all;
    num_disappointed += check_if_disappointed(V);
  }while(next_permutation(V.begin(), V.end()));

  double answer = (double)1 * (num_all - num_disappointed) / num_all;
  cout << fixed << setprecision(12) << answer << endl;
  return 0;
}