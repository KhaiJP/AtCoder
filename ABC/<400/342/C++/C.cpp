#include<iostream>
#include<map>
using namespace std;

map<char, char> m;
int N, Q;
string S;

int main(){
  for(char c = 'a'; c <= 'z'; ++c) m[c] = c;

  cin >> N >> S >> Q;
  
  while(Q--){
    char c, d; cin >> c >> d;
    for(auto &p : m)if(p.second == c){
      p.second = d;
    }
  }

  for(auto c : S) cout << m[c];
  cout << endl;
  return 0;
}