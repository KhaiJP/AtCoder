#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int P[110];
vector<int> F[110];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N){
    cin >> P[i];
    int c; cin >> c;
    rep(j, 0, c){
      int f; cin >> f;
      F[i].push_back(f);
    }
  }
  
  rep(i, 0, N)rep(j, 0, N)if(P[i] > P[j] || P[i] == P[j] && F[i].size() < F[j].size()){
    bool flag;
    for(auto a : F[i]){
      flag = false;
      for(auto b : F[j]) flag = flag || a == b;
      if(!flag) break;
    }
    if(flag){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}