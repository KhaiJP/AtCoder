#include<iostream>
#include<set>
using namespace std;

set<string> s;
string S;
int N;

int main(){
  cin >> S;
  N = S.size();

  for(int i = 0; i < N; ++i){
    for(int j = i; j < N; ++j){
      string T = "";
      for(int k = i; k <= j; ++k) T += S[k];
      s.insert(T);
    }
  }

  cout << s.size() << endl;
  return 0;
}
