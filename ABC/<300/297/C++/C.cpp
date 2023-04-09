#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int H, W; cin >> H >> W;

  rep(i, 0, H){
    string S; cin >> S;
    rep(j, 0, W-1)if(S[j] == 'T' && S[j+1] == 'T'){
      S[j] = 'P';
      ++j;
      S[j] = 'C';
    }
    cout << S << '\n';
  }

  cout << endl;
  return 0;
}