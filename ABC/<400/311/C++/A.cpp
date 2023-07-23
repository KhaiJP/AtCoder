#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool ABC[3];

int main(){
  int N; cin >> N;
  string S; cin >> S;
  rep(i, 0, N){
    ABC[S[i] - 'A'] = true;
    if(ABC[0] && ABC[1] && ABC[2]){
      cout << i+1 << endl;
      return 0;
    }
  }
}