#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int C[200010];
map< int, vector<pair<int, int>> > C_Ri;

int main(){
  int N, T; cin >> N >> T; 

  rep(i, 0, N) cin >> C[i];
  int &C0 = C[0];
  rep(i, 0, N){
    int R; cin >> R;
    if(C[i] == T || C[i] == C0) C_Ri[C[i]].push_back({-R, i+1});
  }
  for(auto &p : C_Ri) sort(p.second.begin(), p.second.end());

  int key = C_Ri.count(T) == 1 ? T : C0; 
  cout << C_Ri[key][0].second << endl;
  return 0;
}