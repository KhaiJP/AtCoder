#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S[110];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> S[i];

  rep(i, 0, N)rep(j, 0, N)if(i != j){
    string t = S[i] + S[j];
    bool flag = true;
    int M = t.size();
    rep(k, 0, M) flag = flag && t[k] == t[M-k-1];
    if(flag){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}