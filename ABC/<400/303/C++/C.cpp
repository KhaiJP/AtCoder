#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<pair<int, int>> cure;

int main(){
  int N, M, H, K; cin >> N >> M >> H >> K;
  string S; cin >> S;
  rep(i, 0, M){
    int x, y; cin >> x >> y;
    cure.insert({x, y});
  }
  
  int x = 0, y = 0;
  rep(i, 0, N){
    if(H == 0){
      cout << "No" << endl;
      return 0;
    }
    
    --H;
    if(S[i] == 'R') ++x;
    if(S[i] == 'L') --x;
    if(S[i] == 'U') ++y;
    if(S[i] == 'D') --y;
    if(H < K && cure.count({x, y}) == 1){
      H = K;
      cure.erase({x, y});
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}
    
  