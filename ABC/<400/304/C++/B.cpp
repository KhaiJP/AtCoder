#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
 
  int div = 1;
  rep(i, 0, 7){
    if(N < div * 1000){
      cout << N / div * div << endl;
      return 0;
    }
    div *= 10;
  }
}