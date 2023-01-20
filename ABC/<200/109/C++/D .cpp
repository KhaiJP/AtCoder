#include<iostream>
#include<vector>
#include<deque>
#include<tuple>
using namespace std;
#define rep(i,s,t) for(int i =(s); i<(t); ++i)

int main(){
  int H, W; cin >> H >> W;
  vector A(H, vector<bool>(W, 0));
  rep(i,0,H)rep(j,0,W){
    int a; cin >> a;
    A[i][j] = a%2==1;
  }
  deque<tuple<int,int,int,int>> procedure;
  rep(i,0,H)rep(j,0,W-1){
    if(A[i][j]){
      procedure.push_back({i, j, i, j+1});
      A[i][j+1] = !A[i][j+1];
    }
  }
  rep(i,0,H-1){
    if(A[i][W-1]){
      procedure.push_back({i, W-1, i+1, W-1});
      A[i+1][W-1] = !A[i+1][W-1];
    }
  }
  cout << procedure.size() << '\n';
  while(!procedure.empty()){
    tuple<int,int,int,int> t = procedure.front(); procedure.pop_front();
    cout << get<0>(t)+1 << ' ' << get<1>(t)+1 << ' ' << get<2>(t)+1 << ' ' << get<3>(t)+1 << '\n';
  }
  return 0;
}