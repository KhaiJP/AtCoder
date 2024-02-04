#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  S.pop_back();
  S += '4';
  cout << S << endl;
}