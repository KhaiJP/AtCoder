#include<iostream>
#include<string>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  ll A[300]; rep(i,0,N) cin >> A[i];
  // dist[i][j] : distance from i to j.
  //price[i][j] : total souvenir price along the shortest path ohter than i 
  ll dist[300][300], price[300][300];
  // set trivial values
  rep(i,0,N)rep(j,0,N){
    dist[i][j]  = (i==j ? 0 : N);
    price[i][j] = 0;
  }
  // set direct flights
  rep(i,0,N){
    string S; cin >> S;
    rep(j,0,N)if(S[j]=='Y'){
      dist[i][j] = 1;
      price[i][j] = A[j];
    }
  }
  // Floyd-Warshall
  rep(k,0,N)rep(u,0,N)rep(v,0,N){
    bool isShorter_path = dist[u][v]   > dist[u][k]  + dist[k][v];
    bool isSame_L_path  = dist[u][v]  == dist[u][k]  + dist[k][v];
    bool isMore_souvnr  = price[u][v]  < price[u][k] + price[k][v];
    if(isShorter_path  ||  ( isSame_L_path && isMore_souvnr )){
      dist[u][v]  = dist[u][k]  + dist[k][v];
      price[u][v] = price[u][k] + price[k][v];
    }
  }
  // deal with queries
  int Q; cin >> Q;
  rep(q,0,Q){
    int U, V; cin >> U >> V; --U, --V;
    if(dist[U][V] == N) cout << "Impossible" << '\n';
    else cout << dist[U][V] << ' ' << price[U][V]+A[U] << '\n';
  }
  cout << endl;
  return 0;
}