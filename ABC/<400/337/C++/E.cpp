#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, cnt;
string S;
vector<int> V[10];

int main(){
  cin >> N;
  rep(i, 1, N)rep(k, 0, 7)if((i&(1 << k)) > 0) V[k].push_back(i);
  rep(k, 0, 7)if(V[k].size()) ++cnt;
  cout << cnt << endl;
  
  rep(k, 0, cnt){
    cout << V[k].size() << ' ';
    for(auto a : V[k]) cout << a << ' ';
    cout << endl;
  }

  cin >> S;
  int answer = 0;
  rep(k, 0, cnt){
    if(S[k] == '1') answer += (1 << k);
  }

  cout << (answer == 0 ? N : answer) << endl;
  return 0;
}