#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
const int64_t pInf64 =  1000000000000000000;

int main(){
  int N, M; cin >> N >> M;
  // Floyd-Warshall, initialization part
  vector fw(N+1, vector<ll>(N+1, pInf64));
  rep(i,1,N+1) fw[i][i] = 0;
  rep(i,1,M+1){
    ll A, B, C; cin >> A >> B >> C;
    fw[A][B] = C;
  }

  // main part
  ll answer = 0;
  rep(k,1,N+1)rep(s,1,N+1)rep(t,1,N+1){
    fw[s][t] = min(fw[s][t], fw[s][k]+fw[k][t]);
    if(fw[s][t] < pInf64) answer += fw[s][t];
  }
  cout << answer << endl;
  return 0;
}