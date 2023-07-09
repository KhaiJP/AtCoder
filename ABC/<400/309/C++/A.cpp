#include<iostream>
using namespace std;

int main(){
  int A, B; cin >> A >> B;
  if(B-A == 1) cout << (A%3 == 0 ? "No" : "Yes") << endl;
  else cout << "No" << endl;

  return 0;
}