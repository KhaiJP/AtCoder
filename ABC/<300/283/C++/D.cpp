#include<iostream>
#include<vector>
#include<map>
#include<string>
#define rep(i, s, t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  string S; cin >> S;
  map<char, int> d;
  vector<int> rmost;
  int i = 0;
  while(!S.empty()){
    if(S[i] == '('){
      rmost.push_back(i);
      i += 1;
    }
    else if(S[i] == ')'){
      int pi = rmost.back(); rmost.pop_back();
      rep(j, pi, i){
        d[S[j]] -= 1;
      }
      S.erase(pi, i-pi+1);
      i = pi;
    }else{
      if(d[S[i]]!=0){
        cout << "No" << endl;
        return 0;
      }else{
        d[S[i]] += 1;
        i += 1;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}