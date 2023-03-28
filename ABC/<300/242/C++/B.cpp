#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  
  multiset<char> ms;
  for(auto c : S) ms.insert(c);
  for(auto c : ms) cout << c;
  cout << endl;
  return 0;
}