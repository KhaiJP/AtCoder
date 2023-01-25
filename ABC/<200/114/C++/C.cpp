#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int table[3] = {3,5,7};

int main(){
  int N; cin >> N;
  int answer = 0;

  rep(ord,3,10){
    int ul = 1;
    rep(i,0,ord) ul *= 3;

    rep(i, 0 , ul){
      bool c[3] = {false, false, false};
      int k = i, tmp = 0;
      
      rep(j, 0, ord){
        tmp = tmp*10 + table[k%3];
        c[k%3] = true;
        k /= 3;
      }
      if(tmp <= N && c[0] && c[1] && c[2]) ++answer;
    }
  }
  cout << answer << endl;
  return 0;
}