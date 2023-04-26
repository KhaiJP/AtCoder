#include<iostream>
#include<map>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string X; cin >> X;
  int N; cin >> N;

  map<char, char> converter;
  rep(i, 0, 26) converter[X[i]] = i + 'a';

  map<string, string> m;
  rep(i, 0, N){
    string S; cin >> S;
    string T = "";
    for(auto c : S) T += converter[c];
    m[T] = S;
  }
  
  for(auto p : m) cout << p.second << endl;
  return 0;
}