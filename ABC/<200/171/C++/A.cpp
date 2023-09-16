#include<iostream>
using namespace std;

int main(){
  char a; cin >> a;
  if(islower(a)) cout << 'a' << endl;
  if(isupper(a)) cout << 'A' << endl;
  return 0;
}