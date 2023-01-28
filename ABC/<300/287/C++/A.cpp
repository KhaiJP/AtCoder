#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  int N; cin >> N;
  int fr = 0, ag = 0;
  rep(i,0,N){
    string S; cin >> S;
    if(S == "For") fr++;
    else ag++;
  }
  cout << (fr>ag ? yes : noo) << endl;
  return 0;
}