#include<iostream>
#include<vector>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int H, W; cin >> H >> W;
  vector A(H, vector<int> (W, 0)); rep(h,0,H)rep(w,0,W) cin >> A[h][w];
  int Hb, Wb; cin >> Hb >> Wb;
  vector B(Hb, vector<int> (Wb, 0)); rep(h,0,Hb)rep(w,0,Wb) cin >> B[h][w];

  rep(dh,0,(1<<H)){
    vector<int> hchoise; rep(i,0,H)if((dh&(1<<i))) hchoise.push_back(i);
    if(hchoise.size()!=Hb) continue;
    rep(dw,0,(1<<W)){
      vector<int> wchoise; rep(i,0,W)if((dw&(1<<i))) wchoise.push_back(i); 
      if(wchoise.size() != Wb) continue;
      bool flag = true;
      rep(h,0,Hb)rep(w,0,Wb) flag = flag && ( A[hchoise[h]][wchoise[w]] == B[h][w]);
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}