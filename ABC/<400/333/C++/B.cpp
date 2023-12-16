#include<iostream>
using namespace std;

bool is_adjacent(char a, char b){
  if(a > b) swap(a, b);
  return b-a == 1 || b-a == 4;
}

int main(){
  string S, T; cin >> S >> T;
  bool fs = is_adjacent(S[0], S[1]);
  bool ft = is_adjacent(T[0], T[1]);
  cout << (fs == ft ? "Yes" : "No") << endl;
  return 0;
}