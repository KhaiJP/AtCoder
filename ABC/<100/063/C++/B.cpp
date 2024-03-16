#include<iostream>
#include<set>
using namespace std;

string S;
set<char> s;

int main(){
  cin >> S;
  for(char c : S) s.insert(c);
  cout << (S.size() == s.size() ? "yes" : "no") << endl;
  return 0;
}