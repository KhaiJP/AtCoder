#include<iostream>
#include<string>
using namespace std;

int main(){
  string N; cin >> N;
  if(N[1]==N[2] && (N[0]==N[1] || N[3]==N[1])) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}