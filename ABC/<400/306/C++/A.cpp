#include<iostream>
using namespace std;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  for(auto c : S) cout << c << c;
  cout << endl;
  return 0;
}