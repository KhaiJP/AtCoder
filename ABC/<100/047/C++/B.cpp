#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int W, H, N; cin >> W >> H >> N;
  vector A(W, vector<int>(H, 1));
  rep(i,0,N){
    int x , y, a; cin >> x >> y >> a;
    if(a==1)         rep(w,0,x) rep(h,0,H) A[w][h] = 0;
    if(a==2 && x!=W) rep(w,x,W) rep(h,0,H) A[w][h] = 0;
    if(a==3)         rep(w,0,W) rep(h,0,y) A[w][h] = 0;
    if(a==4 && y!=H) rep(w,0,W) rep(h,y,H) A[w][h] = 0;
  }
  int answer = 0;
  rep(w,0,W)rep(h,0,H) answer += A[w][h];
  cout << answer << endl;
  return 0;
}