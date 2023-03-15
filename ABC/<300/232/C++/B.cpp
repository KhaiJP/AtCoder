#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  string S, T; cin >> S >> T;
  
  bool flag = true;
  rep(i, 0, S.size()-1){
    flag = flag && ((T[i] - S[i]+26)%26 == (T[i+1] - S[i+1]+26)%26);
  }
  cout << (flag ? yes : noo) << endl;
  return 0;
}