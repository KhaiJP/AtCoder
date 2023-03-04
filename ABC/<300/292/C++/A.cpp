#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#define fore(a, v) for(auto a : v)

int main(){
  string S; cin >> S;
  fore(&c, S) c = toupper(c);
  cout << S << endl;
  return 0;
}