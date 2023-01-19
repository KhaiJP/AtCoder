#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  vector<int> H(N+2, 0); rep(i,1,N+1) cin >> H[i];
  rep(i,0,N+1)if(H[i] >= H[i+1]){cout << H[i] << endl; return 0;}
}