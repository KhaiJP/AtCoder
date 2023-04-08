#include<iostream>
#include<string>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;

  map<int, int> m;
  int ref = 0;
  ++m[ref];
  for(char c : S){
    int nc = c - '0';
    ref = ref ^ (1 << nc);
    ++m[ref];
  }

  int answer = 0;
  for(auto p : m){
    int &a = p.second;
    answer += a * (a - 1) / 2;
  }

  cout << answer << endl;
  return 0;
}