#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  sort(S.begin(), S.end());
  cout << S << endl;
  return 0;
}