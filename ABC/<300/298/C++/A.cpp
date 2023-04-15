#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){

  int N; cin >> N;
  int maru = 0, batu = 0;
  rep(i, 0, N){
    string S; cin >> S;
    for(auto c : S){
      maru += c == 'o';
      batu += c == 'x';
    }
  }

  cout << (maru > 0 && batu == 0 ? "Yes" : "No")<< endl;
  return 0;
}