#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M;
string S;

int main(){
  cin >> N >> M >> S;

  rep(num_to_buy, 0, N+1){
    int n = num_to_buy, m = M;
    bool f = true;
    rep(i, 0, N){
      if(S[i] == '0'){
        n = num_to_buy, m = M;
      }

      if(S[i] == '1'){
        if(m > 0) --m;
        else if(n > 0) --n;
        else{
          f = false;
          break;
        }
      }

      if(S[i] == '2'){
        if(n > 0) --n;
        else{
          f = false;
          break;
        }
      }
    }
    
    if(f){
      cout << num_to_buy << endl;
      return 0;
    }
  }
  return 0;
}