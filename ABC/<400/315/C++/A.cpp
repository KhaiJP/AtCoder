#include<iostream>
#include<string>
using namespace std;

string r = "aeiou";

int main(){
  string S; cin >> S;
  for(auto c : S)if(r.find(c) == string::npos) cout << c;
  cout << endl;
  return 0;
}