#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int P[100010], ranking[100010];

int main(){
  int N, K; cin >> N >> K; --K;
  rep(i, 0, N){
    int p;
    rep(j, 0, 3){cin >> p; P[i] += p;}
    ranking[i] = P[i];
  }sort(ranking, ranking + N, greater<>());

  rep(i, 0, N) cout << (P[i] + 300 >= ranking[K] ? "Yes" : "No") << '\n';

  cout << endl;
  return 0;
}