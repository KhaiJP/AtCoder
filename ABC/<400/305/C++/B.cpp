#include<iostream>
#include<map>
using namespace std;

int main(){
  map<char, int> d;
  d['A'] = 3, d['B'] = 1, d['C'] = 4, d['D'] = 1, d['E'] = 5, d['F'] = 9;

  char p, q; cin >> p >> q;
  if(p > q) swap(p, q);
  
  int answer = 0;
  for(char c = p; c != q; ++c) answer += d[c];
  cout << answer << endl;
  return 0;
}