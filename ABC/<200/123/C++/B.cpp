#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N=5, T[10], answer=1e9;

int main(){
  rep(i, 0, 5) cin >> T[i];
  sort(T, T+N);

  do{
    int idx = 0;
    rep(t, 0, 1000){
      if(t%10 == 0){
        t += T[idx];
        ++idx;
        if(idx == N){
          answer = min(answer, t);
          break;
        }else{
          --t;
        }
      }
    }
  }while(next_permutation(T, T+N));
  
  cout << answer << endl;
  return 0;
}