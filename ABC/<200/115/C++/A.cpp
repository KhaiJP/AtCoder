#include<iostream>
using namespace std;

int main(){
  int D; cin >> D;
  if(D == 25) cout << "Christmas";
  if(D == 24) cout << "Christmas Eve";
  if(D == 23) cout << "Christmas Eve Eve";
  if(D == 22) cout << "Christmas Eve Eve Eve";
  cout << endl;
  return 0;
}