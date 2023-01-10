#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

int main(){
  string S, T; cin >> S >> T;
  int N = S.size();

  // permutation vector
  vector<int> ST(26,-1), TS(26,-1);

  rep(i,0,N){
    int s = int(S[i]-'a'), t = int(T[i]-'a');
    if(ST[s] == -1 && TS[t] == -1){
      ST[s] = t;
      TS[t] = s; 
    }else if(ST[s] == t && TS[t] == s){
      continue; 
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}