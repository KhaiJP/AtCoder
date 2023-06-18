#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int>    FA[100010];
pair<int, int> V[100010];

int main(){
  int N; cin >> N;
  rep(i, 0, 3*N){
    int a; cin >> a; --a;
    FA[a].push_back(i+1);
  }

  rep(i, 0, N){
    sort(FA[i].begin(), FA[i].end());
    V[i] = {FA[i][1], i+1};
  }sort(V, V+N);

  rep(i, 0, N) cout << V[i].second << ' ';
  cout << endl;

  return 0;
}