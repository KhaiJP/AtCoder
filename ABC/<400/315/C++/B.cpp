#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int D[110], M, now, half;

int main(){
  cin >> M;
  rep(i, 0, M) cin >> D[i];
  rep(i, 0, M) half += D[i]; 
  half = half / 2 + 1;
  
  rep(i, 0, M){
    if(now + D[i] >= half){
      cout << i + 1 << ' ' << half - now << endl;
      return 0;
    }
    now += D[i];
  }
}