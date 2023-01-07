#include<iostream>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

int main(){
  const int n = 3;
  vector<int> h(n), w(n); rep(i,0,n) cin >> h[i]; rep(i,0,n) cin >> w[i];
  int answer = 0;
  rep(a_00, 1, h[0])rep(a_01,1,h[0])rep(a_10,1,h[1])rep(a_11,1,h[1]){
    int a_02 = h[0] - (a_00 + a_01); if(a_02 <= 0) continue;
    int a_12 = h[1] - (a_10 + a_11); if(a_12 <= 0) continue;
    int a_20 = w[0] - (a_00 + a_10); if(a_20 <= 0) continue;
    int a_21 = w[1] - (a_01 + a_11); if(a_21 <= 0) continue;
    int a_22 = w[2] - (a_02 + a_12); if(a_22 <= 0) continue;
    if( a_20 + a_21 + a_22  ==  h[2]) ++answer;
  }
  cout << answer << endl;
  return 0;
}